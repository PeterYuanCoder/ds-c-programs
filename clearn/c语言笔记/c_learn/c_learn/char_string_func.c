#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>
#include<string.h>

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
//int islower(int c);

// putchar  输出大写
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
// 
//int main()
//{
//	int r = getchar();      //scanf("%c\n",&r);
//	putchar(r);				//printf("%c\n",r);
//	return 0;
//}





//字符串函数

//strlen函数   查看函数库观察标准形式     统计\0之前的字符串个数

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


//递归模拟实现     无需创建中间变量
//size_t my_strlen(const char* s)
//{
//	if (*s != '\0')
//	{
//		return 1 + my_strlen(s + 1);
//	}
//	else
//		return 0;
//}
//int main()
//{
//	size_t len = my_strlen("abcd");
//	printf("%zu\n", len);
//	return 0;
//}




//strcpy函数    字符串拷贝    会把\0拷贝过去

//int main()
//{
//	char* str[10] = { 0 };
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
//1.找到目标字符\0
// 2.从源字符串中拷贝数据，在目标字符串中\0的位置开始依次覆盖
//char* strcat(char* destination, const char* source);

//int main()
//{
//	char arr1[20] = "hello";
//	char arr2[] = "world";
//	strcat(arr1, arr2);  //将arr2追加到arr1后面
//	printf("%s\n", arr1);
//	return 0;
//}


//模拟实现函数
//char* my_strcat(char* dest, char* src)
//{
//	char* ret = dest;
//	//找\0
//	while (*dest!='\0')
//	{
//		dest++;
//	}
//	//数据的拷贝
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//
//}



//strcmp函数
// 
//int strcmp(const char* str1, const char* str2);

//功能： ?来?较str1和str2指向的字符串，从两个字符串的第?个字符开始?较，如果两个字符
//的ASCII码值相等，就?较下?个字符。直到遇到不相等的两个字符，或者字符串结束


//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abq";
//	int r = strcmp(arr1, arr2);
//	//printf("%d\n", r);
//	if (r > 0)
//	{
//		printf(">\n");
//	}
//	else if (r < 0)
//	{
//		printf("<\n");
//	}
//	else
//	{
//		printf("=\n");
//	}
//	return 0;
//}


//模拟实现函数
//my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2 != NULL);
//	while (*str1 == *str2)
//	{
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;
//}

//strcpy和strcat和strcmp均是长度不受限函数

//strncpy和strncat和strncmp是长度受限函数
//strncpy函数 
// char * strncpy ( char * destination, const char * source, size_t num );
// 
// 不把\0拷贝过去   但是超出字符个数其余补\0
//strncpy函数指定了拷⻉的⻓度，源字符串不⼀定要有思考：
// ⽬标空间的⼤⼩是否够⽤，\0，同时在设计参数的时候，就会多⼀层strncpy相对strcpy函数更加安全


//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "abcdef";
//	strncpy(arr1, arr2, 3);
//	printf("%s\n", arr1);
//	return 0;
//}


//strncat函数      指定追加个数
//char* strncat(char* destination, const char* source, size_t num);


//strncat函数在追加的时候要将源字符串的所有内容，包含\0都追加过去，但是数指定了追加的⻓度。
//strncat函数中源字符串中不⼀定要有\0

//int main()
//{
//	char arr1[20] = "hello";
//	char arr2[20] = "world";
//	strncat(arr1, arr2, 1);
//	printf("%s\n", arr1);
//	return 0;
//}


//strncmp函数    控制比较位数
//int strncmp(const char* str1, const char* str2, size_t num);


//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcqw";
//	int ret1 = strncmp(arr1, arr2, 3);
//	printf("%d\n", ret1);
//	int ret2 = strncmp(arr1, arr2, 4);
//	printf("%d\n", ret2);
//	return 0;
//}


//strstr函数
//在一个字符串中查找子字符串
// 
//char* strstr(const char* str1, const char* str2);

#include<string.h>
//strstr模拟函数
//char* my_strstr(const char* str1, const char* str2)
//{
//	const char* s1;
//	const char* s2;
//	const char* pc = str1;   //特殊情况处理: 当str2是空字符串的时候
//	if (*str2 == '\0')
//		return str1;
//	while (*pc != '\0')
//	{
//		//从pc的位置来时找str2中的字符串
//		s1 = pc;
//		s2 = str2;
//		while (*s2!='\0' && *s1!='\0' && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//			return pc;
//		pc++;
//	}
//}
//int main()
//{
//	char arr1[20] = "abcdefabcdef";
//	char arr2[20] = "def";
//	char* ps = my_strstr(arr1, arr2);  //在arr1中找arr2
//	if (ps != NULL)
//	{
//		printf("%s\n", ps);
//	}
//	else
//	{
//		printf("没有找到\n");
//	}
//	return 0;
//}


//int main()
//{
//    char str[] = "This is a simple string";
//    char* pch;
//    pch = strstr(str, "simple");
//    if (pch != NULL)
//        printf("%s\n", pch);
//    else
//        printf("查找的字符串不存在\n");
//    return 0;
//}


//strtok函数       切割字符串
// 
// strtok会修改源字符串 所以先拷贝一份源字符串
//char* strtok(char* str, const char* delim);

//理解版     不知道多少份就不知道要几个切割语句
//int main()
//{
//	char arr[] = "www.baidu.com";
//	const char* p = ".";     //分隔符的集合
//	char buf[30] = { 0 };
//	strncpy(buf, arr, 30);
//	char* pr = strtok(arr, p);   //第一次切完后续传入NULL表示继续切割同一个字符串
//	printf("%s\n", pr);
//
//	pr = strtok(NULL, p);
//	printf("%s\n", pr);
//
//	pr = strtok(NULL, p);
//	printf("%s\n", pr);
//	return 0;
//}



//即使不知道有多少分也可以直接切割
//int main()
//{
//	char arr[] = "zhangpengwei@yeah.net";
//	const char* p = "@.";
//	char buf[30] = { 0 };
//	strncpy(buf, arr, 30);
//	char* pr = NULL;
//	for (pr = strtok(buf, p); pr != NULL; pr = strtok(NULL, p))
//	{
//		printf("%s\n", pr);
//	}
//	return 0;
//}


//strerror函数
// 
//char* strerror(int errnum);
//#include<errno.h>
//
//int main()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d %s\n", i, strerror(i));
//	}
//	return 0;
//}