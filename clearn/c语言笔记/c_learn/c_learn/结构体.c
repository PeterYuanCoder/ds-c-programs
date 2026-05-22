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




//         4.结构体内存对齐

//1. 结构体的第1个成员对⻬到和结构体变量起始位置偏移量为0的地址处。
//2. 从第2个成员变量开始，都要对⻬到某个对⻬数的整数倍的地址处
//对⻬数 = 编译器默认的⼀个对⻬数与该成员变量⼤⼩的较⼩值。
//VS中默认的值为8 
//Linux中gcc没有默认对⻬数，对⻬数就是成员⾃⾝的⼤
//3. 结构体总⼤⼩为最⼤对⻬数（结构体中每个成员变量都有⼀个对⻬数，所有对⻬数中最⼤的）的整数倍
//4. 如果嵌套了结构体的情况，嵌套的结构体成员对⻬到⾃⼰的成员中最⼤对⻬数的整数倍处，结构
//体的整体⼤⼩就是所有最⼤对⻬数（含嵌套结构体中成员的对⻬数）的整数倍

//#include<stddef.h>
//struct S1
//{
//	char c1;  //1
//	int i;    //4
//	char c2;  //1
//};
//struct S2
//{
//	char c1;   //1
//	char c2;   //1
//	int i;     //4
//};
//
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//
//struct S4
//{
//	char c1;
//	struct S3 s3;
//	double d;
//};
//int main()
//{
//	printf("%zu\n", sizeof(struct S1));
//	printf("%zu\n", sizeof(struct S2));
//	printf("%zu\n", sizeof(struct S3));
//	printf("%zu\n", sizeof(struct S4));
//
//
//
//	//offsetof  是宏 用于求偏移量   需要头文件  stddef.h
//	printf("%d\n", offsetof(struct S1,c1));
//	printf("%d\n", offsetof(struct S1, i));
//	printf("%d\n", offsetof(struct S1, c2));
//
//	return 0;
//}



