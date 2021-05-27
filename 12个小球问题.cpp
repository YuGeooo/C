#include "pch.h"
#include <stdio.h>

int main()
{
	int a[13] = {0};
	int i, z;
	printf("Please choose a ball from 1 to 12 : ");
	scanf_s("%d", &i);//number
	printf("Heavier(1) or lighter(-1) : ");
	scanf_s("%d", &a[i]);//weighht
	if (a[1] + a[2] + a[3] + a[4] > a[5] + a[6] + a[7] + a[8])//进行三次天平称重
		if (a[1] + a[2] + a[5] > a[3] + a[6] + a[9])
		{
			if (a[1] > a[2]) { z = 1; goto next; }
			else if (a[1] < a[2]) { z = 2; goto next; }
			else { z = 6; goto next; }
		}
		else if (a[1] + a[2] + a[5] < a[3] + a[6] + a[9])
		{
			if (a[5] < a[9]) { z = 5; goto next; }
			else { z = 3; goto next;}
		}
		else
		{
			if (a[7] < a[8]){z = 7; goto next;}
			else if (a[7] > a[8]) { z = 8; goto next; }
			else { z = 4; goto next; }
		}
	else if (a[1] + a[2] + a[3] + a[4] < a[5] + a[6] + a[7] + a[8])
		if (a[5] + a[6] + a[1] > a[7] + a[2] + a[9])
		{
			if (a[5] > a[6]) { z = 5; goto next; }
			else if (a[5] < a[6]) { z = 6; goto next; }
			else { z = 2; goto next; }
		}
		else if (a[5] + a[6] + a[1] < a[7] + a[2] + a[9])
		{
			if (a[1] < a[9]) { z = 1; goto next; }
			else { z = 7; goto next; }
		}
		else
		{
			if (a[3] < a[4]) { z = 3; goto next; }
			else if (a[3] > a[4]) { z = 4; goto next; }
			else { z = 8; goto next; }
		}
	else
		if (a[9] + a[10] + a[11] > a[1] + a[2] + a[3])
		{
			if (a[9] > a[10]) { z = 9; goto next; }
			else if (a[9] < a[10]) { z = 10; goto next; }
			else { z = 11; goto next; }
		}
		else if (a[9] + a[10] + a[11] < a[1] + a[2] + a[3])
		{
			if (a[9] < a[10]){z = 9; goto next;}
			else if (a[9] > a[10]) { z = 10; goto next; }
			else { z = 11; goto next; }
		}
		else
		{
			if (a[12] < a[1]) { z = 12; goto next; }
			else { z = 12; goto next; }
		}
next: {
	printf("%d is ", z);
	if (a[z] > 0)printf("heavier");
	else printf("lighter");
	  }
	  return 0;
}