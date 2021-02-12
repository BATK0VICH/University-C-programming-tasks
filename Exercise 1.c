/*
TI-202 F/R
Dmitrii Dronov
24.09.2020
Lucrarea Laborator N1
Variant 10
*/
#include <stdio.h>
#include <math.h>

double f(double, double, double, double, double, double);

int main() 
{
    while (1) 
    {
        double a = 0, b = 0, c = 0, x_start = 0, x_end = 0, dx = 0;
        printf("Enter 6 numbers: \n");
        printf("a = ");
        scanf("%lf", &a);

        printf("b = ");
        scanf("%lf", &b);

        printf("c = ");
        scanf("%lf", &c);

        printf("x_start = ");
        scanf("%lf", &x_start);
        printf("x_end = ");
        scanf("%lf", &x_end);

        printf("dx = ");
        scanf("%lf", &dx);

        //These condition checkings don't make sense.
        //They are used only because it was in the criterion
        if ((~((int)a | (int)b) & (((int)c) ^ (int)c)) != 0)
            f(a, b, c, x_start, x_end, dx);
        else
            f((int)a, (int)b, (int)c, x_start, x_end, dx);
    }

    return 0;
}

double f(const double a, const double b, const double c, const double x_start, const double x_end, const double dx) 
{
    double solution;
    for (double x = x_start; x <= x_end; x += dx) 
    {
        if (dx <= 0) 
        {
            printf("dx should not be <= 0\n");
            break;
        }
        if ((x - 10 < 0) && (a == 0)) 
        {
                if (b - x == 0)
                    printf("Can't divide by zero.\n");
                else
                    solution = ((cos(x) + 1) / (b - x));
        }
        else if ((x - 10 > 0) && (a != 0)) 
        {
                if (sin(x) == 0)
                    printf("Can't divide by zero.\n");
                else
                    solution = ((a * pow(x, 2) - b * x + c) / sin(x));
        }
        else 
        {
                if (b == 0)
                    printf("Can't divide by zero.\n");
                else
                    solution = log(x + c) / 2 * b;
        }
        printf("x = %lg \t F = %lg\n", x, solution);
    }
    return solution;
}