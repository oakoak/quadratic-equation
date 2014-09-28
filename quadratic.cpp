#include "quadraticLib.h"


int quadratic( double coefficients_equation[], double root_equation[])
{
    if((coefficients_equation[2] == 0) && (coefficients_equation[1] == 0) && (coefficients_equation[0] == 0))
                {
                root_equation[0] = 3;
                return 0;
                }

    if ((coefficients_equation[2] == 0) && (coefficients_equation[1] == 0))
        {
        root_equation[0] = NO_ROOTS;
        return 0;
        }

    if (coefficients_equation[2] == 0)
        {
        root_equation[0] = ONE_ROOT;
        root_equation[1] = -coefficients_equation[0]/coefficients_equation[1];
        return 0;
        }

    double discriminant = 0;
    discriminant = coefficients_equation[1]*coefficients_equation[1] - 4*coefficients_equation[2]*coefficients_equation[0];
    if (discriminant < 0)
    {
        root_equation[0] = NO_ROOTS;
    }
    else
    {
        if (discriminant == 0)
        {
            root_equation[0] = ONE_ROOT;
            root_equation[1] =  -coefficients_equation[1]/(2*coefficients_equation[2]);
        }
        else
        {
            root_equation[0] = TWO_ROOTS;
            discriminant = sqrt(discriminant);
            root_equation[1] = ( -coefficients_equation[1] - discriminant) / (2*coefficients_equation[2]);
            root_equation[2] = ( -coefficients_equation[1] + discriminant) / (2*coefficients_equation[2]);
        }
    }
    return 0;
}

int check_values (double coefficients_equation[], double root_equation[])
{
    if (((root_equation[0] == 1) || (root_equation[0] == 2)) && ( coefficients_equation[2]*root_equation[1]*root_equation[1] + coefficients_equation[1]*root_equation[1] + coefficients_equation[0] != 0 ))
        printf("Warning: Root x1 incorrect");

    if ((root_equation[0] == 2) && ( coefficients_equation[2]*root_equation[2]*root_equation[2] + coefficients_equation[1]*root_equation[2] + coefficients_equation[0] != 0 ))
        printf("Warning: Root x2 incorrect");
    return 0;
}


int print_roots (double coefficients_equation [], double root_equation[])
{
    if (root_equation[0] == NO_ROOTS)
        printf("No radicals\n");

    if (root_equation[0] == INFINITELY_ROOTS)
        printf("Infinitely roots\n");

    if (root_equation[0] == ONE_ROOT)
        printf("One root: %lg\n", root_equation[1]);

    if (root_equation[0] == TWO_ROOTS)
        printf("Two root: %lg, %lg\n", root_equation[1], root_equation[2]);

    check_values(coefficients_equation, root_equation);
    return 0;
}
