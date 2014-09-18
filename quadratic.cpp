#include <stdio.h>
#include <math.h>


int quadratic( double a, double b, double c, char* n, double* x1, double* x2)
{
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                *n = 3;
            }
            else
            {
                *n = 0;
            }
        }
        else
        {
            *n = 1;
            *x1 = -c/b;
        }
    }
    else
    {
        double discriminant = 0;
        discriminant = b*b - 4*a*c;
        if (discriminant < 0)
        {
            *n = 0;
        }
        else
        {
            if (discriminant == 0)
            {
                *n = 1;
                *x1 =  -b/(2*a);
            }
            else
            {
                *n = 2;
                discriminant = sqrt(discriminant);
                *x1 = ( -b - discriminant) / (2*a);
                *x2 = ( -b + discriminant) / (2*a);
            }
        }
    }
    return 0;
}

int print_roots (char n, double x1, double x2)
{
    if (n == 0)
        printf("No radicals\n");

    if (n == 3)
        printf("Infinitely roots\n");

    if (n == 1)
        printf("One root: %lg\n", x1);

    if (n == 2)
        printf("Two root: %lg, %lg\n", x1, x2);
    return 0;
}

int main()
{
    double a = 0, b = 0, c = 0;
    printf("enter values a,b,c\n");
    scanf("%lg%lg%lg", &a, &b, &c);
    double x1 = 0,x2 = 0;
    char n = 0;
    quadratic(a, b, c, &n, &x1, &x2);
    print_roots(n, x1, x2);
    return 0;
}
