

static char SccsID[] = "@(#)eval.c	1.1\t4/25/89";

/*************************************************************************
 *									 *
 *     Copyright c 1984 The board of trustees of the Leland Stanford 	 *
 *                      Junior University. All rights reserved.		 *
 *     This subroutine may not be used outside of the SUPREM4 computer	 *
 *     program without the prior written consent of Stanford University. *
 *									 *
 *************************************************************************/
/*   eval.c                Version 3.4     */
/*   Last Modification : 8/23/88  10:37:23 */

#include <stdio.h>
#include <math.h>
extern double erf(), erfc(), pow();
#include <ctype.h>
#include "global.h"
#include "constant.h"
#include "geom.h"
#include "expr.h"

extern char *newget_solval(), *vfunc();


/************************************************************************
 *									*
 *	This file contains the code and definitions for a real		*
 *  number expression evaluator.  The parser is a pseudo LALR job	*
 *  modified to handle this ambiguous grammar.  The grammer rules	*
 *  are :								*
 *	expr  |  expr OP1 expr		OP1 = +,-			*
 *	      |  expr OP2 expr		OP2 = *,/			*
 *	      |  FN expr		FN = implemented functions	*
 *	      |  OP1 expr		unary minus and plus		*
 *	      |  ( expr )		paranthesis			*
 *	      |	 RCONST			real number constant		*
 *	      |  SOLVAL			solution value			*
 *									*
 *  This routine handles the parse tree as developed in reducing this	*
 *  grammar.								*
 *									*
 *  Original:	MEL	8/85						*
 *									*
 ************************************************************************/


/************************************************************************
 *									*
 *	eval_real( expr, val ) - This routine evaluates the real number *
 *  expr contained in the parse tree expr.  If a vector variable is 	*
 *  found, it generates an error.  The value is returned in val when	*
 *  all is said and done.						*
 *									*
 *  Original:	MEL	8/85						*
 *									*
 ************************************************************************/
#ifdef ANSI_FUNC

char *
eval_real (struct vec_str *expr, float *val)
#else

char *eval_real( expr, val )
struct vec_str *expr;
float *val;
#endif
{
    float lval, rval;
    float interface();
    char *err;

    /*evaluate the kids*/
    if ( expr->left != NULL ) 
	if ( (err = eval_real( expr->left, &lval ) ) != NULL ) return(err);

    if ( expr->right != NULL ) 
	if ( (err = eval_real( expr->right, &rval ) ) != NULL ) return(err);

    /*switch on the type of value contained in the passed argument*/
    switch( expr->type ) {
    case OP1 :	/*plus or minus*/
		/*check the unary case out*/
		if (expr->left == NULL) {
		    if ( expr->value.ival == '+' ) *val = rval;
		    if ( expr->value.ival == '-' ) *val = -rval;
		}
		else {
		    if ( expr->value.ival == '+' ) *val = lval + rval;
		    if ( expr->value.ival == '-' ) *val = lval - rval;
		}
		break;
    case OP2 :  /*multiplication / division*/
		if ( expr->value.ival == '*' ) *val = lval * rval;
		if ( expr->value.ival == '/' ) *val = lval / rval;
		break;
    case OP3 :  /*exponentiation*/
		if ( expr->value.ival == '^' ) *val = pow( lval, rval );
		break;
    case FN  :  /*a function specifier*/
		switch( expr->value.ival ) {
		case LOG10 :	*val = log10( rval );
				break;
		case LOG   :	*val = log( rval );
				break;
		case EXP   :	*val = exp( rval );
				break;
		case ERF   :	*val = (double)erf( rval );
				break;
		case ERFC  :	*val = (double)erfc( rval );
				break;
		case ABS   :	*val = (rval > 0.0)?(rval):(-rval);
				break;
		case SQRT  :	*val = (double)sqrt( rval );
				break;
		case SIGN  :	if ( rval > 0.0 ) *val = 1.0;
				else if ( rval < 0.0 ) *val = -1.0;
				else *val = 0.0;
				break;
		case X     :    
		case Y     :    
		case Z     :    if ( (expr->left == NULL) || (expr->right == NULL) ) 
				    return("x,y,and z functions require two arguments\n");
				else 
				    *val = sol_interp( expr->value.ival, lval, rval );
				break;
		default    :    *val = interface( expr->value.ival, rval );
		}
		break;
    case RCONST :  *val = expr->value.dval;
		break;
    case VFN	:
    case SOLVAL :  return( "a vector solution value is illegal here\n" );
		break;
    }
    return( NULL );
}


/************************************************************************
 *									*
 *	eval_vec( expr, val ) - This routine evaluates the real number	*
 *  expr contained in the parse tree expr.  The value is returned in 	*
 *  val when all is said and done.					*
 *									*
 *  Original:	MEL	8/85						*
 *									*
 ************************************************************************/
#ifdef ANSI_FUNC

char *
eval_vec (struct vec_str *expr, float *val)
#else

char *eval_vec( expr, val )
struct vec_str *expr;
float *val;
#endif
{
    float lval[MAXPNT], rval[MAXPNT];
    float tmp;
    char *err;
    int i;

    /*evaluate the kids*/
    if ( expr->left != NULL ) 
	if ( (err = eval_vec( expr->left, lval ) ) != NULL ) return(err);
    if ( expr->right != NULL ) 
	if ( (err = eval_vec( expr->right, rval ) ) != NULL ) return(err);

    /*switch on the type of value contained in the passed argument*/
    switch( expr->type ) {
    case OP1 :	/*plus or minus*/
		/*check the unary case out*/
		if (expr->left == NULL) {
		    if ( expr->value.ival == '+' ) 
			for(i = 0; i < nn; i++) val[i] = rval[i];
		    if ( expr->value.ival == '-' ) 
			for(i = 0; i < nn; i++) val[i] = - rval[i];
		}
		else {
		    if ( expr->value.ival == '+' ) 
			for(i = 0; i < nn; i++) val[i] = lval[i] + rval[i];
		    if ( expr->value.ival == '-' ) 
			for(i = 0; i < nn; i++) val[i] = lval[i] - rval[i];
		}
		break;
    case OP2 :  /*multiplication / division*/
		if ( expr->value.ival == '*' )
			for(i = 0; i < nn; i++) val[i] = lval[i] * rval[i];
		if ( expr->value.ival == '/' )
		    for(i = 0; i < nn; i++) val[i] = lval[i] / rval[i];
		break;
    case OP3 :  /*exponentiation*/
		if ( expr->value.ival == '^' )
		    for(i = 0; i < nn; i++) val[i] = pow( lval[ i], rval[ i]);
		break;
    case FN  :  /*a function specifier*/
		switch( expr->value.ival ) {
		case LOG10 :	for(i=0; i<nn; i++) val[i] = log10(rval[i]);
				break;
		case LOG   :	for(i=0; i<nn; i++) val[i] = log(rval[i]);
				break;
		case EXP   :	for(i=0; i<nn; i++) val[i] = exp(rval[i]);
				break;
		case ERF   :	for(i=0; i<nn; i++) val[i] = erf(rval[i]);
				break;
		case ERFC  :	for(i=0; i<nn; i++) val[i] = erfc(rval[i]);
				break;
		case ABS   :	for(i=0; i<nn; i++) 
				    val[i]=(rval[i]>0.0)?(rval[i]):(-rval[i]);
				break;
		case SQRT  :	for(i=0; i<nn; i++) val[i] = (double)sqrt( rval[i] );
				break;
		case SIGN  :	for(i=0; i<nn; i++)  {
				    if ( rval[i] > 0.0 ) val[i] = 1.0;
				    else if ( rval[i] < 0.0 ) val[i] = -1.0;
				    else val[i] = 0.0;
				}
				break;
		case X     :    
		case Y     :    
		case Z     :    if ( (expr->left == NULL) || (expr->right == NULL) ) 
				    return("x,y,and z functions require two arguments\n");
				else {
				    tmp = sol_interp( expr->value.ival, lval, rval );
				    for(i=0; i <nn; i++) val[i] = tmp;
				}
				break;
		}
		break;
    case RCONST :  for(i = 0; i < nn; i++) val[i] = expr->value.dval;
		break;
    case SOLVAL :  if ( (err = newget_solval( val, expr->value.ival )) != NULL)
			return(err);
		break;
    case VFN    :  if ( (err = vfunc( rval, expr->value.ival, expr->right )) != NULL)
			return(err);
		   for(i=0; i<nn; i++) val[i] = rval[i];
		break;
    }
    return( 0 );
}



/************************************************************************
 *									*
 *	islogexp( expr ) - This routine returns true if the expression	*
 *  starts with a log base 10.  It is used by the plotting software.	*
 *									*
 *  Original:	MEL	12/85						*
 *									*
 ************************************************************************/
#ifdef ANSI_FUNC

int 
islogexp (struct vec_str *expr)
#else

islogexp( expr )
struct vec_str *expr;
#endif
{
    return( (expr->type == FN) && (expr->value.ival == LOG10) );
}




/************************************************************************
 *									*
 *	free_expr - This is a memory disposer.				*
 *									*
 *  Original:	MEL	8/85						*
 *									*
 ************************************************************************/
#ifdef ANSI_FUNC

void 
free_expr (struct vec_str *t)
#else

free_expr( t )
struct vec_str *t;
#endif
{
    if ( t == NULL ) return;
    free_expr( t->left );
    free_expr( t->right );
    free(t);
}
