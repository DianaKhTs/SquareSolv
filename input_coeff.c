#include <stdio.h>

/*!
    @brief  This function demands input of coefficients
    @detailed Checks the right input
    @return Returns nothing
*/
void Input(double* coef_a, double* coef_b, double* coef_c)
{
    printf("Bведите 3 значения коэффициентов:\n");
    while (scanf("%lg  %lg  %lg", coef_a, coef_b, coef_c) != 3)
    {
            printf("Bводите адекватные значения коэффициентов: \n");
            fflush(stdin);
    }
}
