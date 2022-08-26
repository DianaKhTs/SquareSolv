#include "solve_eq.h"

void Input( double* coef_a, double* coef_b, double* coef_c)
{
    CheckPtrs(coef_a);
    CheckPtrs(coef_b);
    CheckPtrs(coef_c);

    printf("Bведите 3 значения коэффициентов: \n");

    scanf("%lg  %lg  %lg", coef_a, coef_b, coef_c);
    if (getchar() != '\n')
    {
        printf("Bводите адекватные значения коэффициентов: \n");
        fflush(stdin);
        Input(coef_a, coef_b, coef_c);
    }
    return;
}