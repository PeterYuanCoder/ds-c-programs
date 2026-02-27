#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//分支语句  if . switch
//循环语句 while ，for , do while
//转向语句 break语句 ， goto语句 ，  continue语句

//if语法
//单分支
//if(表达式)
//	语句1;
//else
//	语句2;
// 
//多分支
//if (表达式1)
//	语句1;
//else if (表达式2)
//	语句2;
//else
//	语句3;


//                               单分支
//int main()
//{
//	int age = 10;
//	if (age >= 18)
//	{                                //  if 后面默认跟一条语句，要想跟多语句要用大括号括起
//		printf("未成年\n");     
//		printf("不能饮酒\n");
//	}
//	else
//		printf("成年\n");
//
//	return 0;
//}
// 
// 
// 
// 
//                              多分支              &&  表示并且的意思       0表示假，非0表示真
//int main()
//{
//	int age = 10;
//	if (age < 18)
//		printf("青少年\n");
//	else if (age >= 18 && age < 28)
//		printf("青年\n");
//	else if ("age>=28&&age<40")
//		printf("中年\n");
//	else if (age > 40 && age < 60)
//		printf("壮年\n");
//	else
//		printf("老年\n");
//	return 0;
//}



int main()
{
	int a = 0;
	int b = 2;
	if (a == 1)
		if (b == 2)
			printf("hehe\n");
		else
			printf("haha\n");
	return 0;
}