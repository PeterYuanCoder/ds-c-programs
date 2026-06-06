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



//3.#define定义宏

//声明方式
//#define name( parament-list ) stuff
//注意：参数列表的左括号必须与name紧邻，如果两者之间有任何空⽩存在，参数列表就会被解释为stuff的⼀部分

//#define SQUARE(x) ((x)*(x))
//这里尽量不要想着节约括号  
//当是  x*x  时候传入宏的是 a+2 时 r = a+2*a+2  不会带括号进行运算
//同理当外面的括号省略时，也会引发错误，所以尽量不要想着省略括号

//int main()
//{
//	int a = 10;
//	int r = SQUARE(a);
//	printf("%d\n", r);
//	return 0;
//}


//4.带有副作用的宏参数

//当宏参数在宏的定义中出现超过⼀次的时候，如果参数带有副作⽤，那么你在使⽤这个宏的时候就可
//能出现危险，导致不可预测的后果。副作⽤就是表达式求值的时候出现的永久性效果

//#define MAX(x,y) ((x)>(y)?(x):(y))
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int z = MAX(a++, b++);//   条件为假执行冒号后面的b++ 导致b多自增一次变成22    b在表达式中出现了2次
//	printf("%d\n", z);
//	printf("a=%d b=%d\n", a, b);
//	return 0;
//}



//5.宏替换的规则

//1.调用时，先检查参数，若参数中有其他#define定义的符号，则先替换参数的
//2.宏参数和#define定义中可以出现其他#define定义的符号。但是对于宏，不能出现递归
//3.当预处理器搜索#define定义的符号的时候，字符串常量的内容并不被搜索