/*
* @Author: Zenith Dandelion
* @Date:   2016-07-14 00:36:06
* @Last Modified by:   Zenith Dandelion
* @Last Modified time: 2016-07-14 00:44:41
*/

#include <stdio.h>
#include <time.h>
#include <omp.h>
#include <windows.h>
#include <iostream>

using namespace std;

__int64 counter_begin;
__int64 counter_end;
__int64 diff;


int main()
{
	freopen("output.txt","w",stdout);
	int n;
	long long muti;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		muti = 1L;
		QueryPerformanceCounter((LARGE_INTEGER *)&counter_begin);
		for(int j = 1; j < i; j++)
			muti *= j;
		QueryPerformanceCounter((LARGE_INTEGER *)&counter_end);
		diff = counter_end-counter_begin;
		cout<<i<<" "<<diff<<" ";
		muti = 1L;
		QueryPerformanceCounter((LARGE_INTEGER *)&counter_begin);
		#pragma omp parallel for reduction(*:muti)
		for(int j = 1; j < i; j++)
			muti *= j;
		QueryPerformanceCounter((LARGE_INTEGER *)&counter_end);
		diff = counter_end-counter_begin;
		cout<<diff<<" "<<muti<<endl;
	}
	return 0;
}


/*

利用OpenMP，计算N!（绘制计算时长随N变化的曲线）。

OUTPUT:

0 1 900 1
1 0 161 1
2 0 139 1
3 1 127 2
4 0 163 6
5 1 199 24
6 1 134 120
7 1 130 720
8 0 167 5040
9 0 159 40320
10 0 172 362880
11 1 174 3628800
12 0 155 39916800
13 0 124 479001600
14 0 124 6227020800
15 0 120 87178291200
16 0 120 1307674368000
17 1 119 20922789888000
18 0 126 355687428096000
19 0 120 6402373705728000

虽然OpenMP开启、关闭线程会有一定的开销
但不是很懂为啥用了OpenMP之后会慢那么多

*/