#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>


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



//字符函数（字符分类函数） 操作字符    比较多需要自己记

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



//写一个代码，将字符串中的小写转大写，其他字符不变
// 运用islower函数 判断是不是小写
// putcher  输出大写
// 
//注意的情况
//int main()
//{
//	//char* str = "abcdef";   //常量区 
//	char str[] = "abcdef";  
//	str[0] = 'A';
//	printf("%c", str);
//	return 0;
//}


//int main()
//{
//	char str[] = "abcdef";
//	int i = 0;
//	while (str[i] != '\0')
//	{
//		//判断当前字符是小写
//		if (islower(str[i]))
//		{
//			//转大写
//			//str[i]=str[i]-32;  //小写a是97  大写A是65
//			putchar(str[i] - 32);
//		}
//		else
//		{
//			putchar(str[i]);
//		}
//		i++;
//	}
//	//printf("%s", str);  //s是打印字符串变量   c是打印字符型变量
//	return 0;
//}


//字符转换函数        
//tolower      大写转小写

//int main()
//{
//	int r = tolower('X');
//	printf("%c\n", r);
//	putchar(r);   //打印字符
//	return 0;
//}

//toupper      小写转大写

//int main()
//{
//	int r = toupper('x');
//	printf("%c\n", r);
//	putchar(r);   //打印字符
//	return 0;
//}



//字符输入和输出
//getchar    从键盘上输入一个字符
//putchar    输出一个字符
//int main()
//{
//	int r = getchar();      //scanf("%c\n",&r);
//	putchar(r);				//printf("%c\n",r);
//	return 0;
//}





//字符串函数

//strlen函数   查看函数库观察标准形式   遇到\0停止

//strlen的函数运行
//size_t my_strlen(const char* str1)
//{
//	assert(str1 != NULL);   //断言
//	int len = 0;
//	while (*str1 != '\0')
//	{
//		len++;
//		str1++;
//	}
//	return len;
//}
//int main()
//{
//	const char* str1 = "abcdef";
//	size_t len = strlen(str1);
//	printf("%zu\n", len);
//	return 0;
//}


//strlen的返回值   返回值类型是size_t        typedef unsigned long long size_t  返回无符号  
// 
//int main()
//{
//	const char* str1 = "abcdef";
//	const char* str2 = "abc";
//	if (strlen(str2) - strlen(str1) > 0)
//	{
//		printf("str2>str1");
//	}
//	else
//	{
//		printf("str1>str2");
//	}
//	return 0;
//}


//指针-指针的方式实现strlen的效果
//int my_strlen(char* str)
//{
//	assert(*str != NULL);
//	char* p = str;
//	while (*p != '0')
//	{
//		p++;
//	}
//	return p - str;  
//}





//strcpy函数    字符串拷贝
//int main()
//{
//	char str[10] = { 0 };
//
//	char* str_source = "abcd";
//
//	strcpy(str, str_source);     //返回值类型是char*
//	printf("%s\n", str);
//	return 0;
//}


//函数形式
//char* my_strcpy(char* str, const char* str_source)
//{
// assert(*str!=NULL)
//	while (*str_source != '0')
//	{
//		*str = *str_source;
//		str_source++;
//		str++;
//	}
//	*str = '\0';  //手动添加一个\0
//}



//strcat函数    追加
//char* strcat(char* destination, const char* source);

//int main()
//{
//	char arr1[20] = "hello";
//	char arr2[] = "world";
//	strcat(arr1, arr2);  //将arr2追加到arr1后面
//	printf("%s\n", arr1);
//	return 0;
//}
