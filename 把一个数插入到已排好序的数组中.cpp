#include "pch.h"
#include <stdio.h>

int main()
{
	int a[] = { 1, 3, 5, 7, 9 };//if change
	int x, i, y, k;
	int b[6];//if change
	printf("现有数组为：1 3 5 7 9\n请输入要插入的数：");
	scanf_s("%d", &x);
	y=sizeof(a)/sizeof(a[0]);//y=5
	for (i = 0;i < y;i++)//i==2   Where x should be.
	{
		if (x< a[i])break;
	}
	for (k = 0;k < i;k++)//k==2
	{
		b[k] = a[k];
	}
	b[i] = x;
	for (k = k + 1;k <= y;k++)//k:3,4,5
	{
		b[k] = a[k - 1];
	}
	printf("新数组为：");
	for (i = 0;i <= y;i++)
	{
		printf("%d ", b[i]);
	}
	return 0;
}