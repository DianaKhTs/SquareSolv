#include <math.h>
#include <stdio.h>

enum num_of_roots {zero , one, two, lots};

void PrintAnswer(int number_of_roots, double* p_x1,  double* p_x2);

/*!
    @brief  This function solves Lineal Equasions
    @return Returns number of roots 
*/
double SolveLinEq( double b, double c, double* p_x1)
{
    if (b == 0 && c == 0)
    {
        return lots;

    }
    if (b != 0)
    {
        *p_x1 = -c/b;
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}

double CountD(double a, double b, double c)
{
    return b * b - a * c * 4;
}

int SolveSqEqWithoutCoeffB(double a, double c, double* p_x1, double* p_x2)
{
    if(c < 0)
    {
        *p_x1 = -sqrt(-c/a);
        *p_x2 =  sqrt(-c/a);
        return 2;
    }
    else if (c == 0)
    {
        *p_x1 = 0;
        return 1;
    }
    else 
    {
        return zero;
    }
}

int SolveSqEqWithoutCoeffC(double a, double b, double* p_x1, double* p_x2)
{
    *p_x1 = 0;
    *p_x2 = SolveLinEq(a, b, p_x1);
    return two;
}

/*!
    @brief  This function solves Square Equasions
    @return Returns number of roots
*/
int SolveSqEq(double a, double b, double c, double* p_x1, double* p_x2)
{  
    if (b == 0)
    {
        return SolveSqEqWithoutCoeffB(a, c, p_x1, p_x2);
    }
    else if (c == 0)
    {
        return SolveSqEqWithoutCoeffC(a, b, p_x1, p_x2);
    }
    else
    {
        double D = CountD(a, b, c);
        if (D > 0)
        {
            double sqrt_D = sqrt(D);
            *p_x1 = (-b + sqrt_D) / (a*2);
            *p_x2 = (-b - sqrt_D) / (a*2);
            return two;
        }
        else if (D == 0)
        {
            *p_x1 = -b/(a*2);
            return one;
        }
        else
        {
            return zero;
        }
    }

}

/*!
    @brief  This function solves Square Equasions
    @detailed Decides whether the function is Lineal or Square 
    @return Returns number of roots
*/
int SolveEq(double a, double b, double c, double* p_x1, double* p_x2)
{
    if (a == 0)
    {
        return SolveLinEq(b, c, p_x1);;
    }
    return SolveSqEq(a, b, c, p_x1, p_x2);
 
}
