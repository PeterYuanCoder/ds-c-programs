#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//                 结构体
// 
// 结构是⼀些值的集合，这些值称为成员变量。结构的每个成员可以是不同类型的变量，如：
//标量、数组、指针，甚⾄是其他结构体
// 
//结构是⼀些值的集合，这些值称为成员变量。结构的每个成员可以是不同类型的变量。



//        1，结构体的定义

//例如描述⼀个学⽣

//struct  是结构关键字
//Stu     是定义名字
//struct Stu
//{
//	//成员列表： 1个或多个
//
//	char name[20];//名字
//		int age;//年龄
//		char sex[5];//性别
//		char id[20];//学号
//}s3,s4; //分号不能丢
////s3 和 s4 也是全局变量
//
//struct Sttu s2; //全局变量  
//int main()
//{
//	struct Stu s1;  //局部变量
//}




//      2，结构体的初始化

//struct Stu
//{
//	char name[20];    //名字
// 	int age;          //年龄
//	float score;      //成绩
//};
//struct Test
//{
//	int n;
//	char c;
//	struct Stu s;
//	double d;
//};
//
//int main()
//{
//	struct Stu s1 = { "李四",18,85.5f };   //按顺序初始化
//	struct Stu s2 = { .score = 65.5f,.age = 12,.name = "王五" };   //不按顺序初始化
//	struct Test t = { 100,'q',{"张三",19,90.5f},3.14 };       //结构体嵌套循环
//
//	//打印结构体的数据
//	printf("%s %d %.1f\n", s1.name, s1.age, s1.score);      //f 前的.1   表示打印一位小数点
//
//	printf("%d %c %s %d %.1f %lf\n", t.n, t.c, t.s.name, t.s.age, t.s.score, t.d);
//	//结构体变量.成员
//	
//	//结构体成员访问操作符
//
//}



//            3.结构体的特殊声明

//匿名结构体类型
//匿名的结构体类型，如果没有对结构体类型重命名的话，基本上只能使⽤⼀次
//struct              //去掉结构体名称 
//{
//	int a;
//	char b;
//	float c;
//}x;
//
//struct
//{
//	int a;
//	char b;
//	float c;
//}*p=&x;
//
//编译器会把上⾯的两个声明当成完全不同的两个类型，所以是⾮法的。

//重命名
//typedef struct       //typedef  是类型重命名
//{
//	int a;
//	char b;
//	float c;
//}Node;         //Node  就是重命名的名字




//结构体的自引用

//struct Node
//{
//	int data;   //数据
//	struct Node* next;  //地址
//};