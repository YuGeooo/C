#include "pch.h"
#include <stdio.h>

int main()
{
	int a[10], i, t, m, n, k=1;
	printf("请输入10个整数：");
	for (i = 0;i < 10;i++)
		scanf_s("%d", &a[i]);
	for (m = 0;m < 9;m++,k++)
	{
		for (n = k;n < 10;n++)
		{
			if (a[m] > a[n])
			{
				t = a[m];
				a[m] = a[n];
				a[n] = t;
			}
		}
	}
	printf("它们从小到大的顺序是：");
	for (i = 0;i < 10;i++)
		printf("%d ", a[i]);
	return 0;
}