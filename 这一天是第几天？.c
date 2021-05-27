#include <stdio.h>

int main()
{
	struct Date
	{
		int year, month, date;
	}a;
	int days(int x, int y, int z);
	printf("请依次输入年、月、日：");
	scanf("%d%d%d", &a.year, &a.month, &a.date);
	printf("该天是这一年的第 %d 天\n", days(a.year, a.month, a.date));
	system("pause");
	return 0;
}

int days(int x, int y, int z)
{
	int m[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }, *p = m, d = 0;
	if (x % 100 != 0 && x % 4 == 0)*(p + 1) = 29;
	else if (x % 400 == 0)*(p + 1) = 29;
	for (;p < m + y - 1;p++)
	{
		d = d + *p;
	}
	d = d + z;
	return d;
}