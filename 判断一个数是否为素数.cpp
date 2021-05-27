#include "pch.h"
#include <stdio.h>

int main()
{
	int prime(int x);
	int a;
	printf("请输入一个整数：");
	scanf_s("%d", &a);
	if (prime(a))
		printf("这个数是素数");
	else
		printf("这个数不是素数");
}

int prime(int x)//判断是否为素数的函数
{
	int i;
	for (i = 2;i < x;i++)
	{
		if (x%i == 0)
		{
			return 0;
			break;
		}
		if (i == x - 1)
			return 1;
	}
}