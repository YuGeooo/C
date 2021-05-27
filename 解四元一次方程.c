#include<stdio.h>
#include<math.h>

int main()
{
	int a[24][4] ={ {1,2,3,4},{1,3,2,4},{1,4,3,2},{1,4,2,3},{1,2,4,3},{1,3,4,2},
	                {2,1,3,4},{2,3,1,4},{2,4,3,1},{2,1,4,3},{2,3,4,1},{2,4,1,3},
	                {3,1,2,4},{3,1,4,2},{3,4,2,1},{3,4,1,2},{3,2,1,4},{3,2,4,1},
	                {4,1,2,3},{4,1,3,2},{4,2,1,3},{4,2,3,1},{4,3,1,2},{4,3,2,1} };                                //1,2,3,4的全排列
	int i, k, j;                                                                                                  //循环变量
	float x[4][5];
	int q, w, e, r;                                                                                               //临时储存
	float D = 0;
	int t;                                                                                                        //t为逆序数
	float y[4] = {0,0,0,0};                                                                                       //Dx1,Dx2,Dx3,Dx4
	float z[4];                                                                                                   //临时储存
	printf("Example: a * x1 + b * x2 + c * x3 + d * x4 = e\n");
	for (i = 0;i < 4;i++)
	{
		printf("\nPlease input a, b, c, d, e :\t");
		scanf("%f%f%f%f%f", &x[i][0], &x[i][1], &x[i][2], &x[i][3], &x[i][4]);
		
	}
	printf("\n\n---------------------Computing------------------------\n\n");
	for (i = 0;i < 24;i++)
	{
		t = 0;
		q = a[i][0];w = a[i][1];e = a[i][2];r = a[i][3];
		if (q > w)t++;
		if (q > e)t++;
		if (q > r)t++;
		if (w > e)t++;
		if (w > r)t++;
		if (e > r)t++;
		D = pow((-1), t)*x[0][q - 1] * x[1][w - 1] * x[2][e - 1] * x[3][r - 1] + D;
	}
	printf("\n   D =");
	for (i = 0;i < 4;i++)
	{
		printf("\n\t|  ");
		for (k = 0;k < 4;k++)
		{
			printf("%5.2f  ",x[i][k]);
		}
		printf("|");
	}
	printf(" = %5.2f\n", D);
	for (j = 0;j < 4;j++)
	{
		for (i = 0;i < 4;i++)
		{
			z[i] = x[i][j];
			x[i][j] = x[i][4];
		}
		for (i = 0;i < 24;i++)
		{
			t = 0;
			q = a[i][0];w = a[i][1];e = a[i][2];r = a[i][3];
			if (q > w)t++;
			if (q > e)t++;
			if (q > r)t++;
			if (w > e)t++;
			if (w > r)t++;
			if (e > r)t++;
			y[j] = pow((-1), t)*x[0][q - 1] * x[1][w - 1] * x[2][e - 1] * x[3][r - 1] + y[j];
		}
		printf("\n   Dx%d =", j + 1);
		for (i = 0;i < 4;i++)
		{
			printf("\n\t|  ");
			for (k = 0;k < 4;k++)
			{
				printf("%5.2f  ", x[i][k]);
			}
			printf("|");
		}
		printf(" = %5.2f\n", y[j]);
		for (i = 0;i < 4;i++)
		{
			x[i][j] = z[i];
		}
		y[j] = y[j] / D;
	}
	printf("\n\n---------------------Result------------------------\n\n");
	printf("\tx1 = %5.2f\tx2 = %5.2f\n\tx3 = %5.2f\tx4 = %5.2f\n\n", y[0], y[1], y[2], y[3]);
	system("pause");
	return 0;
}