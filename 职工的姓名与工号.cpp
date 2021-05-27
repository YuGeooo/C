#include "pch.h"
#include <stdio.h>
#include<string.h>

int main()
{
	void rank(char x[20][10]);
	char a[20][10];
	int i;
	for (i = 0;i < 20;i++)
	{
		scanf_s("%s", a[i], 10);
	}
	rank(a);
	for (i = 0;i < 20;i++)
	{
		printf("%10s", a[i]);
		if (i % 2 != 0)printf("\n");
	}
}

void rank(char x[20][10])
{
	void change(char x[], char y[]);
	int m,n,k=3;
	for (m = 1;m < 19;m + 2, k + 2)
	{
		for (n = k;n < 20;n+2)
		{
			{
				change(x[m], x[n]);
				change(x[m - 1], x[n - 1]);
			}
		}
	}
}

void change(char x[], char y[])
{
	char c[10];
	int i;
	for (i = 0;i < 10;i++)
	{
		c[i] = x[i];
	}
	for (i = 0;i < 10;i++)
	{
		x[i] = y[i];
	}
	for (i = 0;i < 10;i++)
	{
		y[i] =c[i];
	}
}
