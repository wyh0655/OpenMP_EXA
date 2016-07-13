/*
* @Author: Zenith Dandelion
* @Date:   2016-07-13 18:05:35
* @Last Modified by:   Zenith Dandelion
* @Last Modified time: 2016-07-13 18:07:27
*/

#include <stdio.h>
#include <time.h>
#include <omp.h>
#include <windows.h>
#include <stdlib.h>

int main()
{
    clock_t t1 = clock();
#pragma omp parallel num_threads(800)
{
    printf("Hello World! ThreadId = %d\n",omp_get_thread_num());
    Sleep(4000);
}
    clock_t t2 = clock();
    printf("Total time = %ld\n",t2 - t1);

    return 0;
}

// 可以同时打开任务管理器查看实时线程数，会有短暂的线程增加，增加800个线程