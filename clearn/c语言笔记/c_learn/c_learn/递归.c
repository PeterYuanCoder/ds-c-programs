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


//斐波那契函数   求这个数列的第N项     用递归效率太慢了 有重复的计算
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



//循环输出斐波那契
//int fib(int n)
//{
// if(n==1||n==1)
// {
//		return 1;
// }
//	int f1 = 1;
//	int f2 = 1;
//	int f3;
//	for (int i = 3; i <= n; i++)
//	{
//		f3 = f1 + f2;
//		f1 = f2;
//		f2 = f3;
//	}
//	return f3;
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
//



//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222
//int swap(int a)
//{
//	int num = 0;
//	int sum = 0;
//	for (int i = 0; i < 5; i++)
//	{
//		num = num * 10 + a;
//		sum += num;
//	}
//	return sum;
//
//}
//
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int sum = swap(a);
//	printf("%d\n", sum);
//
//	return 0;
//}





//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//输入：1729，输出：19

//int DigitSum(int n)
//{
//	if (n == 0)
//	{
//		return 0;
//	}
//		return (n%10) + DigitSum(n / 10);
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int sum = DigitSum(n);
//	printf("%d\n", sum);
//	return 0;
//}


//编写一个函数实现n的k次方，使用递归实现。
//int swap(int n, int k)
//{
//	
//	if (k == 0)
//	{
//		return 1;
//	}
//		return n * swap(n, k - 1);
//	
//}
//int main()
//{
//	int n,k;
//	scanf("%d %d", &n,&k);
//	int square = swap(n, k);
//	printf("%d", square);
//	return 0;
//}


//递归和非递归分别实现求第n个斐波那契数

//递归
//int fib(int n)
//{
//	if (n == 1 || n == 2)
//	{
//		return 1;
//	}
//	return fib(n - 1) + fib(n - 2);
//}
//int main()
//{
//	int f1 = 1;
//	int f2 = 1;
//	int n;
//	scanf("%d", &n);
//	int ret = fib(n);
//	printf("第%d个斐波那契数是:%d", n, ret);
//	return 0;
//}




//int fib(int n)
//{
//	int f1 = 1;
//	int f2 = 1;
//	int f3;
//	if (n == 1 || n == 2)
//	{
//		return 1;
//	}
//	for (int i = 3; i <= n; i++)
//	{
//		f3 = f1 + f2;
//		f1 = f2;
//		f2 = f3;
//	}
//	return f3;
//}
//
//int main()
//{
//	
//	int n;
//	scanf("%d", &n);
//	int ret = fib(n);
//	printf("第%d个斐波那契数是:%d", n, ret);
//	return 0;
//}
