/*
* @Author: Zenith Dandelion
* @Date:   2016-07-13 21:45:10
* @Last Modified by:   Zenith Dandelion
* @Last Modified time: 2016-07-13 21:51:00
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int matrix_A[10000][10000];
int matrix_B[10000][10000];
long long matrix_C[10000][10000];

int main()
{
    int m,p,n;
    int i,j,k;

    // 矩阵大小，简单起见，m,p,n相等
    printf("请输入0-10000的数字:\n");
    scanf("%d",&n);
    m = p = n ;

    srand((unsigned)time(NULL));

    // 随机生成矩阵
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < p; j++)
            matrix_A[i][j] = rand()%100000;
    }

    for(int i = 0; i < p; i++)
    {
        for(int j = 0; j < n; j++)
            matrix_B[i][j] = rand()%100000;
    }


    clock_t t1 = clock();
    for(int i = 0; i < m; i++)
    {

        for(int j = 0; j < n; j++)
        {
            long long temp = 0L;
            for(int k = 0; k < p; k++)
            {
                temp += matrix_A[i][k]*matrix_B[k][j];
            }
            matrix_C[i][j] = temp;
        }
    }
    clock_t t2 = clock();
    // OpenMP 
    omp_set_num_threads(4);
#pragma omp parallel shared(matrix_A,matrix_B,matrix_C) private(i,j,k)
{
    #pragma omp for schedule(dynamic)
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            long long temp = 0L;
            for(k = 0; k < p; k++)
            {
                temp += matrix_A[i][k]*matrix_B[k][j];
            }
            matrix_C[i][j] = temp;
        }
    }
}
    clock_t t3 = clock();


    printf("普通计算时间 = %ld\n并行计算时间 = %ld\n",t2-t1,t3-t2);


/*
    printf("\n\n\n\nA矩阵\n\n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < p; j++)
        {
            printf("%d ",matrix_A[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n\nB矩阵\n\n");
    for(int i = 0; i < p; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ",matrix_B[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n\nC矩阵\n\n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%ld ",matrix_C[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n\nEND");
*/

    return 0;
}


/*

OUTPUT:

请输入0-10000的数字:
1000
普通计算时间 = 5866
并行计算时间 = 3593

Process returned 0 (0x0)   execution time : 13.653 s

*/