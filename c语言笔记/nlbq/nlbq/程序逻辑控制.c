#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//顺序结构:程序按照代码书写顺序一行一行运行
//选择语句  if语句

int main()
{
	int a = 0;
	//scanf("%d", &a);
	while (scanf("%d", &a) != EOF)
	{
		if (a % 2 != 0)
		{
			printf("%d是奇数\n", a);
		}
		else
		{
			printf("%d是偶数\n", a);
		}
	}
	return 0;
}