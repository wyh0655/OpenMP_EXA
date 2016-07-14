/*
* @Author: Zenith Dandelion
* @Date:   2016-07-14 01:48:15
* @Last Modified by:   Zenith Dandelion
* @Last Modified time: 2016-07-14 17:04:14
*/



/*

// 这道题有很多人这样写，但是这样写有很多限制，并且分别计算字母和数字并不会使速度提升。

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
char String[1000]={""};
int numbers;
int characters;
DWORD WINAPI number(PVOID param) 
{
	for(int i=0;String[i]!='\0';i++)
		if(String[i]>='0'&&String[i]<='9')
			numbers++;
	return 0;
}
DWORD WINAPI character(PVOID param)
{
	for(int i=0;String[i]!='\0';i++)
	{
		if(String[i]>='a'&&String[i]<='z')
			characters++;
		if(String[i]>='A'&&String[i]<='Z')
			characters++;
		}
	return 0;
}
int main()
{	
	numbers=0;
	characters=0;
	FILE * fp_r;
	fp_r=fopen("data.txt","r");	
	int i=0;
	while(fscanf(fp_r,"%c",&String[i])!=EOF)
		i++;	
	fclose(fp_r);		
	HANDLE hThread1=CreateThread(NULL,0,number,NULL,0,NULL);  
	HANDLE hThread2=CreateThread(NULL,0,character,NULL,0,NULL);  	
	HANDLE h[2]={hThread1,hThread2};	
	WaitForMultipleObjects(2,h,TRUE,INFINITE); 
	printf("%d %d\n",numbers,characters);				
	return 0;
}

*/


// 我的想法是将文件划分成几块，用多个线程去读取数据并计算，最终汇总。但是由于不知道怎样传参数最终还是没做出来。
// 继续尝试。。。

#include <stdio.h>
#include <windows.h>
#include <iostream>

using namespace std;

int ascii[178];

DWORD WINAPI ThreadFun1(LPVOID pM)
{
    // 获得文件指针，找到文件开始，遍历到文件中间，记录字母数字个数 
    return 0;
}

DWORD WINAPI ThreadFun2(LPVOID pM)
{
    // 获得文件指针，找到文件中间，遍历到文件末尾，记录字母数字个数 
    return 0;
}
int main()
{
    int ThreadNum;
    cout<<"请输入线程数："<<endl;
    cin>>ThreadNum;
    // 想搞一个用for循环实现的多线程，搞不出来，要考虑好多东西啊
    HANDLE handle1 = CreateThread(NULL, 0, ThreadFun1, NULL, 0, NULL);
    HANDLE handle2 = CreateThread(NULL, 0, ThreadFun2, NULL, 0, NULL);

    WaitForSingleObject(handle1, INFINITE);
    WaitForSingleObject(handle2, INFINITE);

    // 汇总字母数字个数，并输出
    return 0;
}

// 可以改成自定义线程数量