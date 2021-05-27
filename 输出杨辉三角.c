#include <stdio.h>
#include<math.h>

int main()
{
	int a[20] = { 1 }, b[20] = { 1,1 };
	int x = -1, y, z;
	int i;
	printf("%-6d\n%-6d%-6d\n", 1, 1, 1);
	for (z = 3;z <= 20;z++)
	{
		y = pow(x, z);
		if (y < 0)                       //输出奇数行
		{
			for (i = 0;i < z;i++)
			{
				a[i + 1] = b[i] + b[i + 1];
				printf("%-6d", a[i]);
			}
			printf("\n");

		}
		else                             //输出偶数行
		{
			for (i = 0;i < z;i++)
			{
				b[i + 1] = a[i] + a[i + 1];
				printf("%-6d", b[i]);
			}
			printf("\n");
		}
	}
	system("pause");
	return 0;
}