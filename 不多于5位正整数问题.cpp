#include "pch.h"
#include <stdio.h>
#include<iostream>
using std::cin;

int main()
{
	int num, i=1;
	float a, b, c, d, e, num2;
语句1:                                                 //当输入超出范围时的循环结构
	if (i < 999)                                        //限制输入次数
	{
		printf("请输入一个不多于5位的正整数： ");
		scanf_s("%f", &num2);
		num = num2;
		if (num == num2)                               //判断输入的数是否为整数
		{
			if (num < 10 && num > 0)                   //当输入的是一位数时
				printf("\n它是一位数 %d",num);
			else if (num > 9 && num < 100)
			{
				printf("\n它是两位数\n");              //当输入的是两位数时
				a = num / 10;
				b = num % 10;
				printf("它的十位是%1.0f，", a);
				printf("个位是%1.0f\n", b);
				printf("逆序输出为%1.0f", b);
				printf("%1.0f\n", a);
			}
			else if (num > 99 && num < 1000)           //当输入的是三位数时
			{
				printf("\n它是一个三位数\n");
				a = num / 100;
				c = num % 10;
				b = (num - 100 * a - c) / 10;
				printf("它的百位是%1.0f，", a);
				printf("十位是%1.0f，", b);
				printf("个位是%1.0f\n", c);
				printf("逆序输出为%1.0f", c);
				printf("%1.0f", b);
				printf("%1.0f\n", a);
			}
			else if (num > 999 && num < 10000)         //当输入的是四位数时
			{
				printf("\n它是一个四位数\n");
				a = num / 1000;
				b = num % 10;
				c = (num - num % 100 - 1000 * a) / 100;
				d = (num - 100 * c - 1000 * a - b) / 10;
				printf("它的千位是%1.0f，", a);
				printf("百位是%1.0f，", c);
				printf("十位是%1.0f，", d);
				printf("个位是%1.0f\n", b);
				printf("逆序输出为%1.0f", b);
				printf("%1.0f", d);
				printf("%1.0f", c);
				printf("%1.0f", a);
			}
			else if (num > 9999 && num < 100000)       //当输入的是五位数时
			{
				printf("\n它是五位数\n");
				a = num / 10000;
				b = num % 10;
				c = (num - num % 1000 - a * 10000) / 1000;
				d = (num - num % 100 - a * 10000 - c * 1000) / 100;
				e = (num - b - 10000 * a - 1000 * c - 100 * d) / 10;
				printf("它的万位是%1.0f，", a);
				printf("千位是%1.0f，", c);
				printf("百位是%1.0f，", d);
				printf("十位是%1.0f，", e);
				printf("个位是%1.0f\n", b);
				printf("逆序输出为%1.0f", b);
				printf("%1.0f", e);
				printf("%1.0f", d);
				printf("%1.0f", c);
				printf("%1.0f\n", a);
			}
			else
			{
				printf("\n输入超出范围,请重新输入\n\n");
				i++;
				cin.clear();                           //清空缓冲区，防止输入非法字符时跳过输入，陷入无限死循环
				cin.ignore();
				goto 语句1;
			}
		}
		else
		{
			printf("\n输入超出范围,请重新输入\n\n");
			i++;
			cin.clear();
			cin.ignore();
			goto 语句1;
		}
	}
	else
		printf("错误次数过多，已结束");
	return 0;
}