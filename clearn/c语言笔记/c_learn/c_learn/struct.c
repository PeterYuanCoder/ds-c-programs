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


//                 5. 为什么存在内存对齐
//   结构体的内存对齐是拿空间来换时间的做法



//                  6. 在设计结构体时，如何既要满足对齐，又要节省空间
//  将占用空间小的成员尽量集中到一起


//                 7. 如何修改默认对齐数

//#pragma pack(1)    // 1  为默认对齐数
//struct S
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()     //取消设置的默认对齐数，还原为默认
//int main()
//{
//	struct S s; 
//	printf("%d\n", sizeof(struct S));
//	return 0;
//}


//                 8. 结构体传参

//结构体传参的时候，尽量传结构体的地址  节约时间和空间上的体统开销
//struct S
//{
//	int data[1000];
//	int num;
//};
//void print1(struct S t)
//{
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", t.data[i]);
//	}
//	printf("\n");
//	printf("%d\n", t.num);
//}
////结构体指针->成员名   //传入的是地址
//void print2(struct S* ps)
//{
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ",ps->data[i]);
//	}
//	printf("\n");
//	printf("%d\n", ps->num); 
//}
//int main()
//{
//	struct S s = { {1,2,3,4,5},100 };
//	//打印 1
//	print1(s);
//
//	//打印  2
//	print2(&s);
//	return 0;
//}



//            9. 结构体实现位段    位 表示占二进制位

//什么是位段
//1. 位段的成员必须是int、unsigned int或signed int，在C99中位段成员的类型也可以选择其他整型家族类型，⽐如：char。
//2. 位段的成员名后边有⼀个冒号和⼀个数字

//位段
//struct A
//{
//	int _a : 2;    // 占 2个bit 位
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
////结构体
//struct B
//{
//	int _a;   
//	int _b;
//	int _c;
//	int _d;
//};
//int main()
//{
//	printf("%zu\n", sizeof(struct A));
//	printf("%zu\n", sizeof(struct B));
//	return 0;
//}





//       10 . 位段使用的注意事项
//位段的⼏个成员共有同⼀个字节，这样有些成员的起始位置并不是某个字节的起始位置，那么这些位
//置处是没有地址的。内存中每个字节分配⼀个地址，⼀个字节内部的bit位是没有地址的。
//所以不能对位段的成员使⽤& 操作符，这样就不能使⽤scanf直接给位段的成员输⼊值，只能是先输⼊
//放在⼀个变量中，然后赋值给位段的成员


//struct A
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
//int main()
//{
//	struct A sa = { 0 };
//	//scanf("%d", &sa._b);//这是错误的
//
//		//正确的⽰范
//		int b = 0;
//	scanf("%d", &b);
//	sa._b = b;
//	return 0;
//}





//                      二 ， 联合和枚举

//联合体类型的声明
//像结构体⼀样，联合体也是由⼀个或者多个成员构成，这些成员可以是不同的类型。联合体的关键字是union.
//但是编译器只为最⼤的成员分配⾜够的内存空间。联合体的特点是所有成员共⽤同⼀块内存空间。所以联合体也叫共用体


//union Un
//{
//	char c;
//	int i;
//};
//int main()
//{
//	union Un un;
//	printf("%zu\n", sizeof(un));
//	//共用同一块内存空间
//	printf("&un = %p\n", &un);
//	printf("&un.c = %p\n", &(un.c));
//	printf("&un.i = %p\n", &(un.i));
//
//	return 0;
//}



//          1. 联合体大小的计算
//联合体的大小至少是最大成员的大小
//当最大成员的大小不是最大对齐数的整数倍的时候,就要对齐到最大对齐数的整数倍

//union Un
//{
//	char c[5]; //5
//  int i;     //4
//};
//
//int main()
//{
//	
//	printf("%zu\n", sizeof(union Un));
//	return 0;
//}



//        2. 联合体的应用
//图书：书名、作者、⻚数
//杯⼦：设计
//衬衫：设计、可选颜⾊、可选尺⼨

//struct gift_list
//{
//    int stock_number;//库存量
//    double price; //  定价
//    int item_type;//商品类型
//    union {
//        struct
//        {
//            char title[20];//书名
//            char author[20];//作者
//            int num_pages;// ⻚数
//        }book;
//        struct
//        {
//            char design[30];//设计
//        }mug;
//        struct
//        {
//            char design[30];// 设计
//            int colors;//颜色
//            int sizes;//尺⼨
//        }shirt;
//    }item;
//};



//   练习： 使用联合体来判断当前机器是大端还是小端
//int check_sys()
//{
//    union Un
//    {
//        char c;
//        int i;
//    }un;
//    union Un un;
//    un.i = 1;
//    return un.c;// 返回1是小端 ，返回0是大端
//}



//              三， 枚举类型

//    1. 枚举的声明
//enum	是枚举类型的关键字
//enum SEX
//{
//	//枚举类型的可能取值  -  枚举常量
//	MALE,  //0     //记得是打逗号
//	FEMALE=4,//4
//	SECRET   //5
//};
//enum Color
//{
//	RED=3,  //3
//	GREEN, //4
//	BLUE   //5
//};
//
//int main()
//{
//	/*enum SEX sex;
//	enum Color c = RED;*/
//
//	//第一个默认0 ，往后依次加 1
//	printf("%d\n", MALE);
//	printf("%d\n", FEMALE);
//	printf("%d\n", SECRET);
//
//	return 0;
//}


//    2. 枚举的优点
//我们可以使⽤#define 定义常量，为什么⾮要使⽤枚举？
//枚举的优点：
//1. 增加代码的可读性和可维护性
//2. 和#define定义的标识符⽐较枚举有类型检查，更加严谨。
//3. 便于调试，预处理阶段会删除#define 定义的符号
//4. 使⽤⽅便，⼀次可以定义多个常量
//5. 枚举常量是遵循作⽤域规则的，枚举声明在函数内，只能在函数内使用



//     3 枚举类型的使用

//enum Color//颜⾊
//{
//	RED = 1,
//	GREEN = 2,
//	BLUE = 4
//};
//enum Color clr = GREEN;//使⽤枚举常量给枚举变量赋值
