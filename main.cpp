#include "quadraticLib.h"

int main()
{
    const int n = 3;
    double coefficients_equation[n];
    double root_equation[n];
    printf("Enter values a, b, c\n");
    scanf( "%lg%lg%lg" , &coefficients_equation[2], &coefficients_equation[1], &coefficients_equation[0] );
    quadratic(coefficients_equation, root_equation);
    print_roots(coefficients_equation, root_equation);
    return 0;
}
