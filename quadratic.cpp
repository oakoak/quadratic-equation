#include <stdio.h>
#include <math.h>

#define no_roots 0
#define one_root 1
#define two_roots 2
#define infinitely_roots -1

int quadratic( double a, double b, double c, char* n, double* x1, double* x2)
{
    if ((a == 0) && (b == 0) && (c == 0))
    {
        *n = infinitely_roots;
        return 0;
    }

    if ((a == 0) && (b == 0))
    {
        *n = no_roots;
        return 0;
    }

    if (a == 0)
    {
        *n = one_root;
        *x1 = -c/b;
        return 0;
    }

    double discriminant = 0;
    discriminant = b*b - 4*a*c;
    if (discriminant < 0)
    {
        *n = no_roots;
    }
    else
    {
        if (discriminant == 0)
        {
            *n = one_root;
            *x1 =  -b/(2*a);
        }
        else
        {
            *n = two_roots;
            discriminant = sqrt(discriminant);
            *x1 = ( -b - discriminant) / (2*a);
            *x2 = ( -b + discriminant) / (2*a);
        }
    }

    return 0;
}

int check_values (double a, double b, double c, char n, double x1, double x2)
{
    if (((n == one_root) || (n == two_roots)) && ( a*x1*x1 + b*x1 + c != 0 ))
        printf("root x1 is not correct");

    if ((n == two_roots) && ( a*x2*x2 + b*x2 + c != 0 ))
        printf("root x2 is not correct");
    return 0;
}


int print_roots (char n, double x1, double x2)
{
    if (n == no_roots)
        printf("No roots\n");

    if (n == infinitely_roots)
        printf("Infinitely roots\n");

    if (n == one_root)
        printf("One root: %lg\n", x1);

    if (n == two_roots)
        printf("Two root: %lg, %lg\n", x1, x2);

    return 0;
}

int main()
{
    double a = 0, b = 0, c = 0;
    printf("Enter values a, b, c\n");
    scanf("%lg%lg%lg", &a, &b, &c);
    double x1 = 0,x2 = 0;
    char n = 0;
    quadratic(a, b, c, &n, &x1, &x2);
    print_roots(n, x1, x2);
    check_values(a, b, c, n, x1, x2);
    return 0;
}
