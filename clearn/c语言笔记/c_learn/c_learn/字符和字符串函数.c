#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.c>


//补充void类型指针
//int main()
//{
//	int a = 10;
//	char ch = 97;
//
//	void* p = &a;     //不管什么类型的地址  void类型的指针变量都是可以接收的
//	void* pc = &ch;   //不是一个具体的类型， 具有通用性
//
//	printf("%d\n", *p);//在解引用的时候，没有明确的类型所以不知道访问几个字节
//	printf("%c\n", *pc);
//
//	return 0;
//}



//字符函数（字符分类函数） 操作字符

//1.isdigit函数    判断是不是数字字符  限制 十进制'0'-'9'
//int main()
//{
//	char ch = '9';//数字字符
//	int ret = isdigit(ch);
//	if (ret != 0)
//	{
//		printf("这是一个数字字符\n");
//	}
//	else
//	{
//		printf("这不是一个数字字符\n");
//	}
//	return 0;
//}

//2.