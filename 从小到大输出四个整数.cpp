// 从小到大输出四个整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <stdio.h>

int main()
{
	int a, b, c, d, max1, min1, max2, min2, max3, min3, max4, min4, max5, min5;
	printf("请输入四个整数：");
	scanf_s("%d%d%d%d", &a, &b, &c, &d);
	max1 = (a > b) ? a : b;
	min1 = (a < b) ? a : b;
	max2 = (c > d) ? c : d;
	min2 = (c < d) ? c : d;
	max3 = (max1 > max2) ? max1 : max2;
	min3 = (max1 < max2) ? max1 : max2;
	max4 = (min1 > min2) ? min1 : min2;
	min4 = (min1 < min2) ? min1 : min2;
	max5 = (min3 > max4) ? min3 : max4;
	min5 = (min3 < max4) ? min3 : max4;
	printf("它们从小到大的顺序是：%d %d %d %d\n", min4, min5, max5, max3);
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
