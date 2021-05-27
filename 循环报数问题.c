#include <stdio.h>

int main()
{
	void game(int(*x)[100], int y);
	int a[100][100], n;//n是人数
	int(*p)[100] = a;//p为指向二维数组a的指针变量
	printf("请输入参与者的人数：");
	scanf("%d", &n);
	printf("\n游戏结果如下：\n\n");
	game(p, n);
	system("pause");
	return 0;
}

void game(int(*x)[100], int y)
{
	int h = 101, i, k, g = 1, v = 0;//g是报到的数
	for (k = 1;k <= y;k++)printf("%4d", k);//输出参与者的编号
	printf("\n\n");
	for (k = 0;k < 100;k++)
	{
		for (i = 0;i < y;i++)
		{
			if (g > 3)g = 1;//使g在1 2 3中循环
			if (*(*(x + k - 1) + i) == 3)//循环报数时跳过已退出的人
			{
				*(*(x + k) + i) = 3;
				printf("    ");
				continue;
			}
			else *(*(x + k) + i) = g++;//记录这个人报的数
			printf("%4d", *(*(x + k) + i));
			if (h != i)h = i;//记录每次报数是哪个人
			else { v = 101;break; }//当两次都是同一个人报数，即只剩一人时结束两层循环
		}
		printf("\n");
		i = 0;//使指针指向下一圈的第一个人
		if (v == 101)break;
	}
	printf("\n最后留下的是 %d 号\n", h + 1);
}