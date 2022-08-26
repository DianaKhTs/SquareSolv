#include "solve_eq.h"
#include <time.h>
#include <stdio.h>

#define GREEN(str) "\033[1;32m"
#define RED(str) "\033[1;31m"
#define BLACK(str) "\033[0;30"

void INPUTFILE(char* name_of_file)
{
    fgets(name_of_file, 40, stdin);
}

int TestRoots(int num_of_roots_r, double a, double b, double c, double* x1_r_ptr, double* x2_r_ptr)
{
    double x1 = 0, x2 = 0;
    int num_of_roots  = SolveEq(a,b,c, &x1, &x2);
    double x1_r = *x1_r_ptr;
    double x2_r = *x2_r_ptr;

    if (!(num_of_roots == num_of_roots_r) || !(IsEqual(x1,x1_r)) || !(IsEqual(x2,x2_r)))
    {
        printf(RED("FAILED:   num_of_roots = %d, x1 = %lg, x2 = %lg") 
               RED("EXPECTED: num_of_roots = %d, x1 = %lg, x2 = %lg")"\n", num_of_roots, x1, x2, num_of_roots_r, *x1_r_ptr, *x2_r_ptr);
        return 0;
    }
    printf(GREEN(success)"\n");
    return 1;
}


void TestSqEq()
{
    int successfull_tests = 0;
    int failed_tests = 0;

    double a = 0, b = 0, c = 0, x1_r = 0, x2_r = 0;
    int num_of_roots_r = 0;

    //fopen("sqeq.txt", "r");
    
    char name_of_file[40];
    INPUT(name_of_file);

    FILE* fp = fopen(name_of_file, "r");

    while(feof(fp) == 0)
    {
        fscanf(fp, "%lg %lg %lg %lg %lg %d", &a, &b, &c, &x1_r, &x2_r, &num_of_roots_r);

        int ret = TestRoots( num_of_roots_r, a, b, c, &x1_r, &x2_r);
        if (ret == 0)
        {
            failed_tests++;
            continue;
        }
        successfull_tests++;
    }

    printf(BLACK("success in %d cases\n")
           BLACK("failure in %d cases"), successfull_tests, failed_tests);

    fclose(fp); 
}

int main()
{
    TestSqEq();
}
