// 求一元二次方程aX²=bX+c的根.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

int main()
{
	double a, b, c;
	double x1, x2, p;
	printf("请输入 a b c\n");
	scanf_s("%lf%lf%lf",&a, &b, &c);

	if ((p = b * b - 4 * a*c) < 0)
	{
		printf("方程无解\n");
			return 0;
    }
	else if(p==0)
	{
		printf("x1=x2=%f\n", (-b + sqrt(p)) / (2 * a));
		return 0;
	}
	else
	{
		x1 = (-b + sqrt(p)) /( 2 * a);
		x2 = (-b - sqrt(p)) / (2 * a);
		printf("x1=%f x2=%f\n", x1, x2);
	}
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
