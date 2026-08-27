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




//6.宏跟函数的对比

//宏的优点:
//1.宏的运算速度比较快
//2.宏的参数没有类型限制

//宏的缺点：
//1.宏是替换所以当要替换的内容比较长时，程序的长度会大幅提升
//2.宏不方便调试
//3.宏不能递归
//4.宏的优先级书写上,一定要写括号


//但是宏有函数做不到的事
//因为宏对参数类型没有限制，所以当参数类型不用时，函数做不到


//#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
//int main()
//{
//	int* p = MALLOC(4, int);
//	return 0;
//}



//7.#和##


//#运算符
//#运算符将宏的⼀个参数转换为字符串字⾯量。它仅允许出现在带参数的宏的替换列表中


//#define PRINT(val,format) printf("the value of "#val" is " format "\n",val)
////因为预处理器搜索时字符串常量不会被搜索,所以要想输出式子随之变化就需要用#将式子变成字符串进行输出
//int main()
//{
//	int a = 10;
//	PRINT(a, "%d");
//	//printf("the value of a is %d\n",a);
//	return 0;
//}


//##运算符
//##可以把位于它两边的符号合成⼀个符号，它允许宏定义从分离的⽂本⽚段创建标识符。##被称为记号粘合

//   \是续行符
//#define GENERIC_MAX(type) type max_##type(type x,type y)\
//						{\
//							return x>y?x:y;\
//						}
//
//GENERIC_MAX(int);
//GENERIC_MAX(char);
//GENERIC_MAX(float);
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int m1 = max_int(a, b);
//	printf("%d\n", m1);
//	return 0;
//}



//8.命名约定

//一般情况下
//宏名全大写
//函数名不要全部大写



//9.#undef
//用于移除一个宏定义

//#define M 10
//int main()
//{
//	int m = M;
//	#undef M     //移除M
//#define M 1000   //重新定义M
//	printf("%d\n", M);
//	return 0;
//}



//10.命令行定义
//允许在命令⾏中定义符号。⽤于启动编译过程。

//像这样SZ没有定义，我们可以在终端运行是对SZ进行定义
//int main()
//{
//	int arr[SZ];
//	for (int i = 0; i < SZ; i++)
//	{
//		scanf("%d", arr[i]);
//	}
//	for (int i = 0; i < SZ; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}



//11.条件编译

//在编译⼀个程序的时候我们如果要将⼀条语句（⼀组语句）编译或者放弃是很⽅便的
//例如：调试性的代码，删除可惜，保留⼜碍事，所以我们可以选择性的编译



//#define __DEBUG__              //当有__DEBUG__时，被包裹的内容有效，反之无效
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//#ifdef __DEBUG__
//		printf("%d\n", arr[i]);
//#endif
//	}
//	return 0;
//}


//            常见的条件编译指令

//单分支条件编译

//#if 常量表达式
//        //    
//#endif

//#define m 1
//int main()
//{
//#if m==1      //这里一定不能用变量，因为条件编译是在预处理阶段，还没有生成可执行程序
//	printf("hehe\n");
//#endif
//	return 0;
//}


//多分支条件编译

//#if 常量表达式
//           //   
//#elif 常量表达式
//           //   
//#else
//           //   
//#endif


//#define M 5
//int main()
//{
//#if M<5
//	printf("嘻嘻\n");
//#elif M==5
//	printf("哈哈\n");
//#else
//	printf("娜娜\n");
//#endif
//	return 0;
//}



//判断是否被定义

//判断是否被定义
//#if defined(symbol)     //这两个是等效的
//#ifdef symbol

//判断是否没被定义
//#if !defined(symbol) 
//#ifndef symbol 


#define m 0
int main()
{
#ifdef m
	printf("haha\n");
#endif
	return 0;
}


//条件编译的嵌套
//#if defined(OS_UNIX)
//	#ifdef OPTION1
//		unix_version_option1();
//	#endif
//	#ifdef OPTION2
//		unix_version_option2();
//	#endif
//#elif defined(OS_MSDOS)
//	#ifdef OPTION2
//		msdos_version_option2();
//	#endif
//#endif




//12.头文件的包含
//头文件的包含有2种包含
//<> 和  ""

//用 " "包括
//先在源⽂件所在⽬录下查找，如果该头⽂件未找到，编译器就像查找库函数头⽂件⼀样在标准位置查找头⽂件
//如果找不到就提⽰编译错误

//用<>包括
//就是直接从库函数中找头文件


//头文件可能会嵌套导致编程的压力比较大

//我们可以用条件编译来防止头文件的嵌套


//#ifndef __test_c__
//#define __test_c__
////头文件的内容
//#include "test.c"
//#endif

//或者直接用

//#pragma once