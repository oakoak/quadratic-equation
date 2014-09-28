#ifndef QUADRATICLIB_H
#define QUADRATICLIB_H

#include <stdio.h>
#include <math.h>


#define NO_ROOTS 0
#define ONE_ROOT 1
#define TWO_ROOTS 2
#define INFINITELY_ROOTS -1

int quadratic(double coefficients_equation [], double root_equation[]);
/*considers quadratic equations of the form
    a*x^2+b*x+c=0
    b*x+c=0

 input:
    coefficients_equation [] -  an array of coefficients c, b, a
    root_equation[] -           reference to an array which will roots of the equation (root_equation[] - number of roots)
*/
int check_values (double coefficients_equation [], double root_equation[]);
/*checks for compliance with the roots
*/
int print_roots (double coefficients_equation [], double root_equation[]);
/*displays the roots
*/
#endif
