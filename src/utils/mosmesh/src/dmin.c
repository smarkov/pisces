/*----------------------------------------------------------------------
**  Copyright 1988 by
**  The Board of Trustees of the Leland Stanford Junior University
**  All rights reserved.
**
**  This routine may not be used without the prior written consent of
**  the Board of Trustees of the Leland Stanford University.
**----------------------------------------------------------------------
**/


/* dmin - returns the minimum of 2 inputs */

/*  in the case of a tie, the first one is returned */

#ifdef ANSI_FUNC

double 
dmin (double a, double b)
#else

double dmin( a, b )
double a;
double b;
#endif
{
    if (a <= b)
	return(a);
    else
	return(b);
}
