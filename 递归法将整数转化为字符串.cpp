#include "pch.h"
#include <stdio.h>

int main()
{
	void apart(int x);
	int a;
	printf("请输入一个整数：");
	scanf_s("%d", &a);
	apart(a);
}
void apart(int x)
{
	int y = x * 10;
	if (x > 10)
	{
		x = x / 10;
		y = y / 10;
		apart(x);
		printf("%d", y % 10);

	}
	else
	{
		printf("%d", x);
	}
}