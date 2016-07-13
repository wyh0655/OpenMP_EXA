/*
* @Author: Zenith Dandelion
* @Date:   2016-07-13 16:57:57
* @Last Modified by:   Zenith Dandelion
* @Last Modified time: 2016-07-13 16:59:46
*/

#include <stdio.h>
#include <time.h>

void test()
{
    int a = 0;
    clock_t t1 = clock();
    for(int i = 0; i < 100000000; i++)
        a = i + 1;
    clock_t t2 = clock();
    printf("TestTime = %d\n", t2 - t1);
}

int main()
{
    clock_t t1 = clock();
#pragma omp parallel for
    for(int j = 0; j < 2; j++)
        test();
    clock_t t2 = clock();
    printf("Total time = %d\n",t2 - t1);
    
    test();
    return 0;
}


/*
OUTPUT:

TestTime = 340
TestTime = 341
Total time = 342
TestTime = 312

Process returned 0 (0x0)   execution time : 0.668 s
*/