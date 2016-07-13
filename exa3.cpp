/*
* @Author: Zenith Dandelion
* @Date:   2016-07-13 18:13:16
* @Last Modified by:   Zenith Dandelion
* @Last Modified time: 2016-07-13 18:14:35
*/

#include <stdio.h>
#include <time.h>
#include <omp.h>
#include <windows.h>
#include <stdlib.h>

int main()
{
    clock_t t1 = clock();
    omp_set_nested(true);
#pragma omp parallel num_threads(2)
{
    printf("First level. ThreadId = %d\n",omp_get_thread_num());
    #pragma omp parallel num_threads(2)
    {
        printf("Second level. ThreadId = %d\n",omp_get_thread_num());
    }
}
    clock_t t2 = clock();
    printf("Total time = %ld\n",t2 - t1);

    return 0;
}

/*
嵌套执行

OUTPUT:

First level. ThreadId = 0
First level. ThreadId = 1
Second level. ThreadId = 0
Second level. ThreadId = 1
Second level. ThreadId = 0
Second level. ThreadId = 1
Total time = 1

Process returned 0 (0x0)   execution time : 0.014 s

*/