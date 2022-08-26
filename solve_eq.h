
#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include "assert.h"
#include <time.h>

enum num_of_roots {ZERO , ONE, TWO, INF};

/*!
    @param[in] coef_a  coeff_a - coefficient
    @param[in] coef_b  coeff_b - coefficient
    @param[in] coef_c  coeff_c - coefficient
    @brief  This function asks for input correct coefficients
    @detailed Decides whether coefficients are suitable or not
*/
void INPUTFILE(double* coef_a, double* coef_b, double* coef_c);

/*!
    @brief  This function solves Square Equations
    @detailed Decides whether the function is Linear or Square 
    @return Returns number of roots
*/
int SolveEq(double a, double b, double c, double* p_x1, double* p_x2);

/*!
    @brief  This function solves Linear Equations
    @return Returns number of roots 
*/
int SolveLinEq( double b, double c, double* p_x1, double* p_x2);

/*!
    @brief  This function prints the answer
    @return Returns nothing
*/
void PrintAnswer(int number_of_roots, double* p_x1,  double* p_x2);

/*!
    @brief  This function solves Square Equations
    @return Returns number of roots
*/
int SolveSqEq( double a, double b, double c, double* p_x1, double* p_x2);

int IsEqual(double y, double z);

void CheckPtrs(double* ptr);
