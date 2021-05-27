#include "pch.h"
#include <stdio.h>

int main()
{
	void ud(char x[],int y);
	int i, k;//k为字符串的长度
	char c[99];
	printf("请输入一个字符串：");
	for (i = 0;i < 99;i++)
	{
		scanf_s("%c", &c[i]);
		if (c[i] == '\n')//按下回车时结束输入
		{
			k = i;//记录输入字符串的长度
			for (;i < 99;i++)//未赋值的为\0
			{
				c[i] = '\0';
			}
			break;
		}
	}
	ud(c,k);
	printf("倒序后为：");
	for (i = 0;i < 99;i++)
	{
		printf("%c", c[i]);
	}
}

void ud(char x[],int y)//把字符组倒序的函数
{
	int i, k;
	char a[99];
	for (i = 0, k = 98;i < 99;i++)
	{
		for (;k >= 0;k--)
		{
			if (x[k] != '\0')
			{
				a[i] = x[k];//a为原字符组的倒序
				k--;
				break;
			}
		}
	}
	for (i=y;i < 99;i++)//未赋值的为\0
	{
		a[i] = '\0';
	}
	for (i = 0;i < 99;i++)
	{
		x[i] = a[i];//使原字符组与a相同
	}
}