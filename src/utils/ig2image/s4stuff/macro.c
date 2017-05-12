

static char SccsID[] = "@(#)macro.c	1.1\t4/25/89";

/*************************************************************************
 *									 *
 *   Original : MEL         Stanford University        Sept, 1984	 *
 *									 *
 *     Copyright c 1984 The board of trustees of the Leland Stanford 	 *
 *                      Junior University. All rights reserved.		 *
 *     This subroutine may not be used outside of the SUPREM4 computer	 *
 *     program without the prior written consent of Stanford University. *
 *									 *
 *************************************************************************/
/*   macro.c                Version 3.4     */
/*   Last Modification : 10/29/88  08:46:56 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "shell.h"
#include "expr.h"
extern char *strpbrk();


char *arg_expand(char *s, struct macro_table *mac);
char *list_parse(char **s, int first );

/************************************************************************
 *									*
 *	dump_macro( macro ) - this routine outputs all of the macros 	*
 *  under defintion to stdout.						*
 *									*
 *	Original	Mark E. Law		Sept, 1984		*
 *									*
 ************************************************************************/
#ifdef ANSI_FUNC

int 
dump_macro (struct macro_table *macro)
#else

dump_macro( macro )
struct macro_table *macro;
#endif
{
    struct macro_table *temp;
    int i;

    /*display each macro on a new line*/
    for(temp = macro; temp != NULL; temp = temp->next) {
	/*this is easy...*/
	if ( temp->args != NULL ) 
	    printf("%s%s\t%s\n", temp->name, temp->args, temp->replace);
	else
	    printf("%s\t%s\n", temp->name, temp->replace );
    }
}



/************************************************************************
 *									*
 * 	define_macro(str, macro) - this macro takes the string passed 	*
 *  and parses it to build a new macro entry.  				*
 *									*
 *	Original	Mark E. Law		Sept, 1984		*
 *									*
 ************************************************************************/
#ifdef ANSI_FUNC

int 
define_macro (char *str, struct macro_table **macro)
#else

define_macro(str, macro)
char *str;
struct macro_table **macro;
#endif
{
    struct macro_table *temp;
    int i;
    char name[256];
    char args[256];
    char *body;
    struct vec_str *out;
    char *t, *m;
    float val;


    /*eat any white space at the start of the string*/
    while ( isspace( *str ) ) str++ ;

    /*copy into name until end of name portion.
      The end of the name is defined to be either white space, or
      a parenthesis. 
    */
    for(t = str; isalnum( *t ); t++);

    if (t == str) {
	if (strlen(str) == 0)
	    dump_macro( *macro );
	else {
	    fprintf(stderr, "macro names have to consist of alphanumerics\n");
	    return( -1 );
	}
    }

    /*parse the argument list, if any*/
    if ( *t == '(' ) {
	/*stick the name part away*/
	*t = '\0';	strcpy(name, str);	*t = '(';
	m = t;

        /*process the argument portion*/
	while( (*t) && (*t != ')') ) t++;

	/*skip over the last character of the macro name*/
	t++;

	/*make sure we found that closing paren*/
	if (! *t) {
	    fprintf(stderr, "The macro argument list is not closed\n");
	    return( -1 );
	}
	/*copy the argument portion away*/
	*t++ = '\0';
	strcpy(args, m);
    }
    else {
	/*add a null terminator and copy into name*/
	*t++ = '\0';
	strcpy(name, str);
	strcpy(args, "");
    }

    /*set up the replacement by walking over the spaces*/
    while ( isspace( *t ) ) t++;

    if (*t == '\0') {
	/*error!!!*/
	fprintf(stderr, "There is no macro body for %s\n", name);
	return(-1);
    }

    /*undefine any old one that may be there*/
    undef_macro(name, macro);
    
    /*first malloc space for the new entry*/
    temp = (struct macro_table *)malloc(sizeof(struct macro_table));
    temp->next = macro[0];
    macro[0] = temp;

    /*copy the macro name*/
    temp->name = (char *)malloc( strlen(name) + 1);
    strcpy(temp->name, name);
    if (strlen(args) == 0)
	temp->args = NULL;
    else {
	temp->args = (char *)malloc( strlen(args) + 1);
	strcpy(temp->args, args);
    }

    /*save the current body in a safe place*/
    body = (char *)malloc( strlen(t) + 20);
    strcpy(body, t);

    /*check the body to see if it can be expanded by the expression parser*/
    if ( (parse_expr( t, &out )) == NULL ) {
	if ( (eval_real( out, &val )) == NULL )
	    sprintf(body, "%g", val);
    }
	
    if ( out != NULL ) free_expr( out );

    /*copy the replacement portion*/
    temp->replace = (char *)malloc( strlen(body) + 1);
    strcpy(temp->replace, body);

    free( body );
}




/************************************************************************
 *									*
 *	expand_macro(macro) - this routine works on the common input 	*
 *  buffer.  It looks at the macro passed to it and the current input	*
 *  state to determine if this macro needs to be expanded.		*
 *									*
 *	Original	Mark E. Law		Sept, 1984		*
 *									*
 ************************************************************************/
#ifdef ANSI_FUNC

int 
expand_macro (char **expand_str, int *len, struct macro_table *macro)
#else

expand_macro( expand_str, len, macro )
char **expand_str;
int *len;
struct macro_table *macro;
#endif
{
    int i, j;
    char *s, *t;
    char *save;
    char *sep;
    char *buf;
    char *body;
    char name[80];
    int length, test, nl;
    struct macro_table *mac;
    int domac = TRUE;

    /*if no macros to check, return*/
    if (macro == NULL) return( 0 );
    
    for( buf = *expand_str; *buf; ) {

	/*if we happened to have stopped on a % sign, stop macro expansion*/
	if ( *buf == '%' ) {
	    /*replace with a space for the parser*/
	    domac = FALSE;
	    buf++;
	}

	save = buf;
	    
	/*if $ signals for expansion, do it*/
	if ( *buf == '$' ) {

	    /*find the next token for checking*/
	    if ( *(buf+1) == '{' ) {
		/*find the end of the bracket set*/
		for( buf+=2, nl=0;  *buf && ( *buf != '}' ); name[nl++] = *(buf++) );
		buf++;
	    }
	    /*macros must be alphanumeric*/
	    else 
		for( buf++, nl=0; isalnum( *buf ) ; name[nl++] = *(buf++) );
	    mac = macro;
	}
	else  {
	    for( nl=0; isalnum( *buf ) ; name[nl++] = *(buf++) );
	    if ( domac ) 
		mac = macro;
	    else 
		mac = NULL;
	}

	name[nl] = '\0';

	while (mac != NULL && strcmp( mac->name, name) != 0)
	    mac = mac->next;

	/*if mac is non-null, we have a match*/
	if ( mac != NULL ) {
	    
	    /*check for arguments in this pup*/
	    if (*buf == '(' ) {
		/*returns a pointer to the string to be put in*/
		body = arg_expand(buf, mac);
		if (body == NULL) {
		    fprintf(stderr, "argument mismatch with macro\n");
		    return( -1 );
		}
		/*advance s past the end of the macro args*/
		while( *buf != ')' ) buf++;
		buf++;
	    }
	    else
		body = mac->replace;
		    
	    /*save the portion after the macro*/
	    s = (char *)malloc( strlen(*expand_str) + 1);
	    strcpy(s, buf);

	    /*check the size of the whole mess*/
	    if ( (j = strlen(*expand_str) + strlen(body) + 1) > *len ) {
		length = save - *expand_str;
		*len = 2 * j;
		*expand_str = (char *)realloc(*expand_str, *len);
		save = *expand_str + length;
	    }

	    /*put in the replacement portion*/
	    for(t = body; *save = *t;  save++, t++ ) ;
    
	    /*now copy on the save portion*/
	    strcpy(save, s);
	    free( s );
	    buf = save;
	}
	while ( *buf && !isalnum( *buf ) && (*buf != '$') && (*buf != '%') ) buf++;
    }
    return(0);
}



/************************************************************************
 *									*
 *	undef_macro(name, macro) - this routine searched through the 	*
 *  macro tables to find a macro to remove.				*
 *									*
 *	Original	Mark E. Law		Sept, 1984		*
 *									*
 ************************************************************************/
#ifdef ANSI_FUNC

int 
undef_macro (char *name, struct macro_table **macro)
#else

undef_macro(name, macro)
char *name;
struct macro_table **macro;
#endif
{
    struct macro_table *old, *mac;
    char *t;

    /*strip leading white space*/
    while( isspace( *name ) ) name++;

    /*strip trailing white space*/
    for(t = (name + strlen(name)); isspace(*t); *t-- = '\0');

    for(old = NULL, mac = macro[0]; (mac != NULL) && strcmp(mac->name, name);
       old = mac, mac = mac->next);
    
    if (mac == NULL)
	/*didn't find a match*/
	return(-1);

    /*free data space*/
    if (mac->name != NULL) free(mac->name);
    if (mac->args != NULL) free(mac->args);
    if (mac->replace != NULL) free(mac->replace);

    /*adjust the pointers*/
    if (old == NULL) {
	macro[0] = mac->next;
	free(mac);
	}
    else {
	old->next = mac->next;
	free(mac);
	}
}






/************************************************************************
 *									*
 *	arg_expand(s , mac) - This routine expands the argument list	*
 *  and returns a pointer to the replacement string to be used.		*
 *									*
 *  Original:	MEL	2/85						*
 *									*
 ************************************************************************/
#ifdef ANSI_FUNC

char *arg_expand(char *s, struct macro_table *mac)
#else

char *
arg_expand (s, mac)
char *s;
struct macro_table *mac;
#endif
{
    char *argvalue[20];
    char *argnames[20];
    char *body;
    char *list, *args;
    char str[256];
    int i;
    int cval, cnam;
    struct macro_table *m = NULL;

    list = (char *)malloc( strlen(s) + 1);
    strcpy(list, s);
    args = (char *)malloc( strlen(mac->args) + 1);
    strcpy(args, mac->args);

    /*now build the array of strings*/
    for(cval=0; (argnames[cval]=(char *)list_parse(&args,FALSE)) != NULL; cval++);

    for(cnam=0; (argvalue[cnam]=(char *)list_parse(&list,FALSE)) != NULL; cnam++);

    /*if we don't get the same number, exit*/
    if ( (cval != cnam) || (cval == 0) ) return( NULL );

    /*build a sub macro table from these pups*/
    for(i = 0; i < cval; i++) {
	strcpy(str, argnames[i]);
	strcat(str, " ");
	strcat(str, argvalue[i]);
	define_macro(str, &m);
    }

    /*do little recursion by calling the routine which called us*/
    body = (char *)malloc(i = 256);
    strcpy(body, mac->replace);
    strcat(body, "\n");		/*this is to get the last part of the string*/
    expand_macro(&body, &i, m);
    body[ strlen(body)-1 ] = '\0';

    /*free space*/
    while ( m != NULL ) undef_macro( m->name, &m );
    for(i = 0; i < cval; i++) {
	free( argnames[i] );
	free( argvalue[i] );
    }
    free(list);
    free(args);

    return( body );
}
