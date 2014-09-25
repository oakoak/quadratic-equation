#include "quadratic.cpp"

int main()
{
    double a = 0, b = 0, c = 0;
    double x1 = 0,x2 = 0;
    char n = 0;
    read ( a, b, c );
    quadratic(a, b, c, n, x1, x2);
    print_roots(n, x1, x2);
    check_values(a, b, c, n, x1, x2);
    return 0;
}
