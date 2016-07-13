/*
* @Author: Zenith Dandelion
* @Date:   2016-07-14 01:04:50
* @Last Modified by:   Zenith Dandelion
* @Last Modified time: 2016-07-14 01:24:40
*/


#include <iostream>
#include <windows.h>
using namespace std;

int N;
__int64 counter_begin;
__int64 counter_end;
__int64 diff;
DWORD WINAPI fuc1 (LPVOID param)
{
	__int64 * factorial=(__int64 *)param;
	for(int i = 1; i < N/2; i++)
		*factorial = (*factorial)*i;
	return 0;
}
DWORD WINAPI fuc2(LPVOID param)
{
	__int64 * factorial=(__int64 *)param;
	for(int i = N/2; i <= N; i++)
		*factorial = (*factorial)*i;
	return 0;
}
int main()
{
	cin>>N;
	long long fact[2] = {1,1};
	long long factorial = 1L;
	QueryPerformanceCounter((LARGE_INTEGER *)&counter_begin);
	HANDLE hThread1 = CreateThread(NULL,0,fuc1,&fact[0],0,NULL);
	HANDLE hThread2 = CreateThread(NULL,0,fuc2,&fact[1],0,NULL);
	HANDLE h[2]={hThread1,hThread2};
	WaitForMultipleObjects(2,h,TRUE,INFINITE);
	factorial = fact[0]*fact[1];
	QueryPerformanceCounter((LARGE_INTEGER *)&counter_end);
	cout<<N<<"!="<<factorial<<endl;
	diff=counter_end-counter_begin;
	cout<<"Time = "<<diff<<endl;
	return 0;
}

// 利用WindosAPI多线程函数计算N!，局部变量