#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double nr_itr(double (*f)(double), double (*d)(double), double x)
{
    return x - (f(x) / d(x));
}

double f(double x)
{
    return 2 * x * x - 1;
}

double d(double x)
{
    return 4 * x;
}

double nr(double (*f)(double), double (*d)(double), double x0, double epsilon)
{
    double ei = 0;
    double xp = x0;
    double xn = x0;
    int itr = 0;
    printf("k = %d; xn = %lf;\n", itr, xn);
    ++itr;
    do
    {
        xn = nr_itr(f, d, xp);
        ei = fabs(xn - xp);
        xp = xn;
        
        printf("k = %d; x = %lf; e = %lf;\n", itr, xn, ei);
        ++itr;
    }
    while(ei > epsilon);
    return xn;
}

int main()
{
    /*double x0 = 3;
    printf("%lf\n", x0);
    
    double x1 = nr_itr(f, d, x0);
    printf("%lf\n", x1);
    
    double x2 = nr_itr(f, d, x1);
    printf("%lf\n", x2);
    
    double x3 = nr_itr(f, d, x2);
    printf("%lf\n", x3);
    
    double x4 = nr_itr(f, d, x3);
    printf("%lf\n", x4);
    
    double x5 = nr_itr(f, d, x4);
    printf("%lf\n", x5);*/
    
    
    double x0 = 3;
    double xn = nr(f, d, x0, 0.01);
    printf("%lf\n", xn);

    return 0;
}
