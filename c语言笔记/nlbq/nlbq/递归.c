#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int fac(int n)
{
	if (n == 1)
	{
		return 1;
	}
	int tmp = n * fac(n - 1);
}
int main()
{
	int ret= fac(5);
	printf("%d", ret);
	return 0;
}