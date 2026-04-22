#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//顺序结构:程序按照代码书写顺序一行一行运行
//选择语句  if语句

//int main()
//{
//	int a = 0;
//	//scanf("%d", &a);
//	while (scanf("%d", &a) != EOF)
//	{
//		if (a % 2 != 0)
//		{
//			printf("%d是奇数\n", a);
//		}
//		else
//		{
//			printf("%d是偶数\n", a);
//		}
//	}
//	return 0;
//}



//int main()
//{
//	int n = 0;
//	if (!n)
//	{
//		printf("%d", !n);
//	}
//	return 0;
//}



//输入一个月份，如果是在3月到5月之间输出春季
//int main()
//{
//	int month;
//	scanf("%d", &month);
//	if (month >= 3 && month <= 5)
//	{
//		printf("春季\n");
//	}
//	return 0;
//}


//“短路”与
// a&&b 
// 如果表达式1为假那么整个表达式必定为假，此时就不会再对b进行求值这种情况就称为“短路”



//输入一个年份year,判断year是否是闰年
//int main()
//{
//	int year;
//	scanf("%d", &year);
//	if (year % 4 == 0 || year % 100 != 0 && year % 400==0)
//	{
//		printf("%d是闰年\n", year);
//	}
//	else
//	{
//		printf("%d不是闰年\n",year);
//	}
//	return 0;
//}



//switch语句
//swith(整形语句)          //case 后面有空格
//{
//	case 整数常量1:语句;   //case用于匹配情况  ，结尾用break跳出swith语句
//	case 整数常量2:语句;   
//	default:语句;      //default用于 运行不匹配的情况
//}






//循环语句

//在屏幕上打印1-10的值
//int main()
//{
//	int i = 0;
//	/*for (i = 0; i <= 10; i++)
//	{
//		printf("%d ", i);
//	}*/
//
//	/*while (i<=10)
//	{
//		printf("%d ", i);
//		i++;
//	}*/
//
//
//	return 0;
//}



//输入一个正的整数，逆序打印这个整数的每一个
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	while (a != 0)
//	{
//		printf("%d ", a % 10);
//		a = a / 10;
//	}
//	return 0;
//}




//求n的阶乘
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int i = 1;
//	int ret = 1;
//	while (i <= a)
//	{
//		ret *= i;
//		i++;
//	}
//	printf("%d", ret);
//	return 0;
//}





//求n的阶乘和
//int main()
//{
//	int b;
//	scanf("%d", &b);
//	int j = 1;
//	int sum = 0;
//	while (j <= b)
//	{
//		int i = j;
//		int a = 1;
//		int ret = 1;
//		while (a <= i)
//		{
//			ret = ret * a;
//			a++;
//		}
//		sum += ret;
//		j++;
//	}
//	printf("sun=%d\n", sum);
//	return 0;
//}



//求1-100之间2的倍数的数字之和
//int main()
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 0; i <= 100; i++)
//	{
//		if (i % 2 == 0)
//		{
//			sum += i;
//		}
//	}
//	printf("%d", sum);
//	return 0;
//}



//do while();循环    至少执行一回

//int main()
//{
//	int i = 1;
//	do
//	{
//		printf("%d", i);
//		i++;
//	} while (i <= 10);
//	return 0;
//}



//循环嵌套

//int main()
//{
//	for (int i = 1; i < 10; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d * %d= %-2d ", j, i,i*j);          //左对齐用- 数 ，  右对齐用 +数  //2指的是空格
//		}
//		printf("\n");
//	}
//	return 0;
//}



//break

//找到1-100之间第一个能被3整除的数字，要求使用break
//int main()
//{
//	int i = 1;
//	while (i <= 100)
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d ", i);
//			break;
//		}
//		i++;
//	}
//	return 0;
//}



//continue
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//		{
//			i++;
//			continue;
//		}
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}


//找到1-100之间所有能被3整除的数字，要求使用continue
//int main()
//{
//	int i = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d ", i);
//			continue;
//		}
//	}
//	return 0;
//}


//编写程序数1-100之间的所有整数中出现多少的数字9

//int main()
//{
//	int i = 0;
//	int ret = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			ret++;
//		}
//		if(i / 10 == 9)
//		{
//			ret++;
//		}
//	}
//	printf("%d", ret);
//	return 0;
//}


//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值，打印出结果

//int main()
//{
//	double n = 1.0;
//	int i = 1.0;
//	double sum = 0.0;
//	double sum1 = 0.0;
//	double sum2 = 0.0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 0)
//		{
//			sum1 = sum1 + 1.0 / i;
//		}
//		else
//		{
//			sum2 = sum2 + 1.0 / i;
//		}
//	}
//	sum = sum2 - sum1;
//	printf("%f", sum);
//	return 0;
//}




//求10 个整数中最大值

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int max = arr[0];
//	for (int i = 0; i <= 10; i++)
//	{
//		if (arr[i] >= max)
//		{
//			max = arr[i];
//		}
//		
//	}
//		printf("%d", max);
//		
//	return 0;
//}




//写一个代码打印1-100之间所有3的倍数的数字

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}