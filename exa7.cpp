/*
* @Author: Zenith Dandelion
* @Date:   2016-07-14 01:11:13
* @Last Modified by:   Zenith Dandelion
* @Last Modified time: 2016-07-14 01:24:42
*/


#include <iostream>
#include <windows.h>
using namespace std;

int N;
long long factorial;
__int64 counter_begin;
__int64 counter_end;
__int64 diff;
CRITICAL_SECTION cs; 

DWORD WINAPI fuc1(PVOID param)
{	 
	for(int i = 1; i < N/2; i++)
	{ 
		EnterCriticalSection(&cs);
		factorial = factorial*i;
		LeaveCriticalSection(&cs);
	
	}
	return 0;
} 

DWORD WINAPI fuc2(PVOID param)
{
	 
	for(int i = N/2;i <= N;i++)
	{
		EnterCriticalSection(&cs);
		factorial = factorial*i;
		LeaveCriticalSection(&cs);
	}
	return 0;
}  

int main()
{
	cin>>N;
	factorial = 1L;	
	InitializeCriticalSection (&cs);
	QueryPerformanceCounter((LARGE_INTEGER *)&counter_begin);	
	HANDLE hThread1 = CreateThread(NULL,0,fuc1,NULL,0,NULL);
	HANDLE hThread2 = CreateThread(NULL,0,fuc2,NULL,0,NULL);
	HANDLE h[2] = {hThread1,hThread2};	
	WaitForMultipleObjects(2,h,TRUE,INFINITE); 	
	QueryPerformanceCounter((LARGE_INTEGER *)&counter_end);
	cout<<N<<"!="<<factorial<<endl;	
	diff=counter_end-counter_begin;
	cout<<"Time = "<<diff<<endl;	
	return 0;
		
}

// 利用WindosAPI多线程函数计算N!，共享变量