#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int fac(int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	int tmp = n * fac(n - 1);
//}
//int main()
//{
//	int ret= fac(5);
//	printf("%d", ret);
//	return 0;
//}




//递归求1+2+3+4+.....N的和
//int sum(int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	return n + sum(n - 1);
//}
//int main()
//{
//	int ret = sum(5);
//	printf("%d", ret);
//	return 0;
//}



//顺序打印一个整数的每一位

//void ever(int n)
//{
//	if (n < 10)
//	{
//		printf("%d\n", n);
//		return;
//	}
//	ever(n / 10);
//	printf("%d\n", n%10);
//}
//
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	ever(a);
//	return 0;
//}


//void ever(int n)
//{
//	if (n > 9)
//	{
//		ever(n / 10);
//	}
//	printf("%d\n", n % 10);
//}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	ever(a);
//	return 0;
//}



//递归求一个数字N的每一位的和
//int ever(int n)
//{
//	if (n < 10)
//	{
//		return n;
//	}
//	return (n % 10) + ever(n / 10);
//}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int sum = ever(a);
//	printf("%d\n", sum);
//	return 0;
//}


//斐波那契函数   求这个数列的第N项
//int fib(int n)
//{
//	if (n == 1 || n == 2)
//	{
//		return 1;
//	}
//	return fib(n - 1) + fib(n - 2);
//}
//
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int ret = fib(a);
//	printf("%d\n", ret);
//	return 0;
//}