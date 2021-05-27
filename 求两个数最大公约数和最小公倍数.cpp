#include "pch.h"
#include <stdio.h>

int main()
{
	int gcd(int x, int y);
	int lcm(int x, int y);
	int m, n ;
	printf("请输入两个正整数：");
	scanf_s("%d%d", &m, &n);
	printf("它们的最大公约数是%d\n", gcd(m,n));
	printf("它们的最小公倍数是%d\n", lcm(m,n));
}

int gcd(int x, int y)//求最大公约数的函数
{
	int r;
	do
	{
		r = x % y;
		x = y;
		y = r;
	} while (r != 0);
	return x;
}

int lcm(int x, int y)//求最小公倍数的函数
{
	int z;
	return x * y / gcd(x, y);
}