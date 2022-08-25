#include <stdio.h>
#include "solve_eq.h"

int main()
{
    /*!
    @param[in] coef_a  coeff_a - coefficient
    @param[in] coef_b  coeff_b - coefficient
    @param[in] coef_c  coeff_c - coefficient
    */
    double coef_a = 0, coef_b = 0, coef_c = 0;
    double x1 = 0, x2 = 0;

    Input(&coef_a, &coef_b, &coef_c);
    PrintAnswer(SolveEq(coef_a, coef_b, coef_c, &x1, &x2), &x1, &x2);
}
