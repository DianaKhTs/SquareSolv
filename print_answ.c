
#include <math.h>
#include <stdio.h>

enum num_of_roots {zero , one, two, lots};
/*!
    @brief  This function prints the answer
    @return Returns nothing
*/
void PrintAnswer(int number_of_roots, double* p_x1,  double* p_x2)
{
    
    switch (number_of_roots)
    {
        case zero:
            printf("нет действительных решений");
            break;
        case one:
            printf("x = %1.3lg",*p_x1);
            break;
        case two:
            printf("x1 = %1.3lg, x2 = %1.3lg", *p_x1, *p_x2);
            break;
        case lots:
            printf("any solution");
            break;
        default:
            printf("ERROR");
            break;
    }
}