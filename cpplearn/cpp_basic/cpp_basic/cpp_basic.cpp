#define _CRT_SECURE_NO_WARNINGS
#include"cpp_basic.h"

//第一个C++程序
#include<iostream>
using namespace std;
//int main()
//{
//	cout << "Hello World" << endl; 
//}



//                                        命名空间

#include <stdio.h>
#include <stdlib.h>

//重定义
//int rand = 10;
//int main()
//{
//	// 编译报错: error C2365 : "rand" : 重定义; 以前的定义是"函数"
//	printf("%d", rand);
//	return 0;
//}


//1.正常命名空间的定义
//namespace space
//{
//    // 命名空间中可以定义变量/函数/类型
//    int rand = 10;
//
//    int Add(int left, int right)
//    {
//        return left + right;
//    }
//
//    struct Node
//    {
//        struct Node* next;
//        int val;
//    };
//}
//
//int main()
//{
//    //默认访问全局的rand
//    printf("%d\n", rand);
//
//    //指定space命名空间中的rand
//    printf("%d\n", space::rand);
//    return 0;
//}


//2. 命名空间的嵌套
//namespace space
//{
//	namespace ping
//	{
//		int rand = 1;
//		int add(int x, int y)
//		{
//			return x + y;
//		}
//	}
//	namespace pa
//	{
//		int rand = 2;
//		int add(int x, int y)
//		{
//			return (x + y) * 10;
//		}
//	}
//}
//
//int main()
//{
//	printf("%d\n", space::ping::rand);
//
//	printf("%d\n", space::pa::rand);
//
//	return 0;
//}


//3.using展开命名空间中对部分
//namespace space
//{
//	int a = 1;
//	int b = 2;
//}
//
//int main()
//{
//	using space::a;
//	printf("%d\n", a);
//	return 0;
//}


//4. using 全部展开
//namespace space
//{
//	int a = 1;
//	int b = 2;
//}
//
//int main()
//{
//	using namespace space;
//	printf("%d\n", a);
//	printf("%d\n", b);
//	return 0;
//}


//               缺省参数

//全缺省
//void Func(int a = 10, int b = 20,int c=30)
//{
//	cout << a << " " << b << " " << c << endl;
//}
//
//int main()
//{
//	Func();//没有传参是使用默认值
//	Func(5, 6, 7);//传参后使用实参
//	return 0;
//}


//半缺省
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << a << " " << b << " " << c << endl;
//}
//
//int main()
//{
//	Func();//没有传参是使用默认值
//	Func(5);//只传部分参数，其余的使用默认参数
//	Func(5, 6);
//	Func(5, 6, 7);
//	return 0;
//}


//                     函数重载
//// 1、参数类型不同
//int Add(int left, int right)
//{
//    cout << "int Add(int left, int right)" << endl;
//    return left + right;
//}
//
//double Add(double left, double right)
//{
//    cout << "double Add(double left, double right)" << endl;
//    return left + right;
//}
//
//// 2、参数个数不同
//void f()
//{
//    cout << "f()" << endl;
//}
//
//void f(int a)
//{
//    cout << "f(int a)" << endl;
//}
//
//// 3. 参数结构顺序不同
//void f(int a, char b)
//{
//    cout << "f(int a,char b)" << endl;
//}
//void f(char b, int a)
//{
//    cout << "f( char b,int a)" << endl;
//}


//                                  引用
//int main()
//{
//	int a = 0;
//	int& b = a;
//	int& c = a;
//	//值
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//	//地址
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	return 0;
//}


// 1. 引用的特性
//int main()
//{
//	int a = 10;
//	//编译报错：ra必须初始化
//	//int& ra;
//	int& b = a;
//
//	int c = 20;
//	b = c;       //c++引用不能改变指向，这是一个赋值操作
//
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	return 0;
//}


//2. const引用
//int main()
//{
//	const int a = 10;
//	// 编译报错: error C2440: “初始化”: 无法从“const int”转换为“int &”
//	// 这里的引用是对a访问权限的放大
//	//int& ra = a;
//
//	// 这样才可以
//	const int& ra = a;
//	// 编译报错: error C3892: “ra”: 不能给常量赋值
//	//ra++;
//
//	// 这里的引用是对b访问权限的缩小
//	int b = 20;
//	const int& rb = b;
//	// 编译报错: error C3892: “rb”: 不能给常量赋值
//	//rb++;
//
//	return 0;
//}



//                 内联函数

//inline int Add(int x, int y)
//{
//	int ret = x + y;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//
//	return ret;
//}
//
//int main()
//{
//	// 可以通过汇编观察程序是否展开
//	// 有call Add语句就是没有展开，没有就是展开了
//	int ret = Add(1, 2);
//	cout << Add(1, 2) * 5 << endl;
//	return 0;
//}


//               nullptr
//#include<iostream>
//using namespace std;
//
//void f(int x)
//{
//	cout << "f(int x)" << endl;
//}
//
//void f(int* ptr)
//{
//	cout << "f(int* ptr)" << endl;
//}
//
//int main()
//{
//	f(0);
//	// 本想通过f(NULL)调用指针版本的f(int*)函数，但是由于NULL被定义成0，调用了f(int x)，因此与程序的初衷相悖。
//	f(NULL);
//	f((int*)NULL);
//
//	// 编译报错: error C2665: “f”: 2 个重载中没有一个可以转换所有参数类型
//	// f((void*)NULL);
//
//	f(nullptr);
//
//	return 0;
//}
