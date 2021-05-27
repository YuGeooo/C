#include "pch.h"
#include <stdio.h>

int main()
{
	void sort(char x[10]);
	char a[10];
	int i;
	printf("请输入10个字符：");
	for (i = 0;i < 10;i++)
		scanf_s("%c", &a[i]);
	printf("\n");
	sort(a);
	printf("它们从小到大的顺序为：");
	for (i = 0;i < 10;i++)
		printf("%c ", a[i]);
	printf("\n");
	return 0;
}
void sort(char x[10])
{
	void change(char &x, char &y);
	int i, j;
	for (j = 0;j < 9;j++)
		for (i = 0;i < 9;i++)
			if (x[i] > x[i + 1])
			{
				change(x[i], x[i + 1]);
			}
}
void change(char &x, char &y)
{
	char t;
	t = x;
	x = y;
	y = t;
}
