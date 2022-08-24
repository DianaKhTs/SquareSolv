#include <stdio.h>
#include "solve_eq.h"



int main()
{
    double coef_a = 0, coef_b = 0, coef_c = 0;
    double x1 = 0, x2 = 0;

    while (scanf("%lg  %lg  %lg", &coef_a, &coef_b, &coef_c) != 3)
    {
       // printf("%lg  %lg  %lg", coef_a, coef_b, coef_c);
        printf("error");
        fflush(stdin);
    }
   
    PrintAnswer(SolveEq(coef_a, coef_b, coef_c, &x1, &x2), &x1, &x2);
}