
#include <math.h>
#include <stdio.h>
#include "solve_eq.h"

void PrintAnswer(int number_of_roots, double* p_x1,  double* p_x2)
{
    CheckPtrs(p_x1);
    CheckPtrs(p_x2);

    switch (number_of_roots)
    {
        case ZERO:
            printf("нет действительных решений");
            break;
        case ONE:
            printf("x = %1.3lg\n",*p_x1);
            printf("x = %.3lg",*p_x1);
            break;
        case TWO:
            printf("x1 = %1.3lg, x2 = %1.3lg", *p_x1, *p_x2);
            break;
        case INF:
            printf("any solution");
            break;
        default:
            printf("ERROR");
            break;
    }
}