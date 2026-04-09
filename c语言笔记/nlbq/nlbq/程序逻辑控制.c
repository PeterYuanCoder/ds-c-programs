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
