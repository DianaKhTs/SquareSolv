#include "solve_eq.h"

int  IsEqual(double y, double z)
{
    const double EPS = 0.000001;
    return (fabs(y - z) < EPS);
}

void CheckPtrs(double* ptr)
{
    assert(ptr != NULL);   
}

void SortRoots(double* p_x1, double* p_x2)
{
    CheckPtrs(p_x1);
    CheckPtrs(p_x2);

    if (*p_x1 > *p_x2)
    {
        double temp = *p_x1;
        *p_x1 = *p_x2;
        *p_x2 = temp;
    }
}

int SolveLinEq( double b, double c, double* p_x1, double* p_x2)
{
    CheckPtrs(p_x1);
    CheckPtrs(p_x2);

    if (IsEqual(b,0) && IsEqual(c,0))
    {
        return INF;
    }
    if (!IsEqual(b,0))
    {
        *p_x1 = -c/b;
        *p_x2 = *p_x1;

        return ONE;
    }
    else
    {
        return ZERO;
    }   
}

double CountD( double a, double b, double c)
{
    return b * b - a * c * 4;
}

int SolveSqEqWithoutCoeffB( double a, double c, double* p_x1, double* p_x2)
{
    CheckPtrs(p_x1);
    CheckPtrs(p_x2);

    if(c < 0)
    {
        double sqrt_x = sqrt(-c/a);
        *p_x1 = -sqrt_x;
        *p_x2 =  sqrt_x;
        return TWO;
    }
    else if (IsEqual(c,0))
    {
        *p_x1 = 0;
        return ONE;
    }
    else 
    {
        return ZERO;
    }
}

int SolveSqEqWithoutCoeffC( double a, double b, double* p_x1, double* p_x2)
{
    CheckPtrs(p_x1);
    CheckPtrs(p_x2);

    *p_x1 = 0;
    *p_x2 = SolveLinEq(a, b, p_x1, p_x2);
    return TWO;
}

/*!
    @brief  This function solves Square Equations
    @return Returns number of roots
*/
int SolveSqEq( double a, double b, double c, double* p_x1, double* p_x2)
{  
    CheckPtrs(p_x1);
    CheckPtrs(p_x2);

    if (IsEqual(b,0))
    {
        return SolveSqEqWithoutCoeffB( a, c, p_x1, p_x2);
    }
    else if (IsEqual(c,0))
    {
        return SolveSqEqWithoutCoeffC( a, b, p_x1, p_x2);
    }
    else
    {
        double D = CountD( a, b, c);
        if (IsEqual(D,0))
        {
            *p_x1 = -b/(a*2);
            *p_x2 = *p_x1;
            return ONE;
        }
        else if (D > 0)
        {
            double sqrt_D = sqrt(D);
            *p_x1 = (-b + sqrt_D) / (a*2);
            *p_x2 = (-b - sqrt_D) / (a*2);
            SortRoots( p_x1, p_x2);
            return TWO;
        }
        else
        {
            return ZERO;
        }
    }
}

int SolveEq(double a, double b, double c, double* p_x1, double* p_x2)
{
    if (IsEqual(a,0))
    {
        return SolveLinEq( b, c, p_x1, p_x2);;
    }
    return SolveSqEq( a, b, c, p_x1, p_x2);
}

