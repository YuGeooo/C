#include "pch.h"
#include <stdio.h>

int main()
{
	int mi(int *x);
	int a[3], *p, ret, i, k;
	printf("请输入3个整数：");
	for (p = a;p < (a + 3);p++)
		scanf_s("%d", p);
	p = a;
	ret = mi(p);
	k = ret % 10;
	i = (ret - k) / 10;
	printf("%d %d %d\n", *(p + i), *(p + k), *(p + 3 - i - k));
	printf("%d %d %d", *a, *(a + 1), *(a + 2));
	return 0;
}
int mi(int *x)
{
	int min, i, k;
	{
		min = *x;
		i = 0;
		if (*(x + 1) < *(x + 2))k = 1;
		else k = 2;
	}
	if (min > *(x + 1))
	{
		min = *(x + 1);
		i = 1;
		if (*x < *(x + 2))k = 0;
		else k = 2;
	}
	if (min > *(x + 2))
	{
		i = 2;
		if (*x < *(x + 1))k = 0;
		else k = 1;
	}
	return 10 * i + k;
}