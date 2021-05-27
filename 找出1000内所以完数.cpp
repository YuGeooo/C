#include "pch.h"
#include <stdio.h>

int main()
{
	int i, x, k, f;
	for (x = 1; x <= 1000; x++)
	{
		k = 0;
		for (i = 1; i < x; i++)
		{
			if (x % i == 0)
			{
				k = k + i;
				if (k == x)     //当x是完数时
				{
					printf("%d its factors are ", x);
					for (i = 1; i < x; i++)     //输出它的每一个因数
					{
						if (x % i == 0)
						{
							printf("%d", i);
							for (f = 2; x % f == 0; f++)     //格式控制                 
							{
								if (i != x / f)printf(",");break;
							}	
						}
					}
					printf("\n");
				}
			}
		}
	}
	return 0;
}