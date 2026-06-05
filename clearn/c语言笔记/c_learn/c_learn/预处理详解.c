#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//继前面编译的翻译环境中的预处理步骤

//   1.预定义符号
//C语⾔设置了⼀些预定义符号，可以直接使⽤，预定义符号也是在预处理期间处理的

//int main()
//{
//	printf("%s\n", __FILE__);   //进行编译的源文件
//	printf("%d\n", __LINE__);   //文件当前的行号
//	printf("%s\n", __DATE__);   //文件被编译的日期
//	printf("%s\n", __TIME__);   //文件被编译的时间
//	//printf("%d\n", __STDC__);   //如果编译器遵循ANST C，其值为1，否则为定义
//	return 0;
//}


//2.#define定义常量

//语法：
//#define name stuff    //（不用加;）
//相当于用name来替换stuff


//#define MAX 100
//#define pf printf
//int main()
//{
//	printf("%d\n", MAX);
//	pf("%d\n", MAX);
//	return 0;
//}
