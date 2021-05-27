#include <stdio.h>
#include<string.h>

int main()
{
	void swap(char x[], char y[], char z[]);
	char s1[10], s2[10], s3[10];
	printf("请输入3个字符串：");
	scanf("%s%s%s", s1, s2, s3);
	swap(s1, s2, s3);
	printf("%s %s %s\n", s1, s2, s3);
	system("pause");
	return 0;
}
void swap(char x[], char y[], char z[])
{
	void change(char *x, char *y);
	char *p1 = x, *p2 = y, *p3 = z;
	if (strcmp(x, y) == 1)change(p1, p2);
	if (strcmp(x, z) == 1)change(p1, p3);
	if (strcmp(y, z) == 1)change(p2, p3);
}
void change(char *x, char *y)
{
	char c[10];
	char *z = c;
	while (z < c + 10)
	{
		*z = *x;
		*x++ = *y;
		*y++ = *z++;
	}
}

