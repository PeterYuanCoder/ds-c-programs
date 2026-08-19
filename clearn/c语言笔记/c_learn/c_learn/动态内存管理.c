#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//静态内存


//int val = 20; //在栈空间上开辟4个字节
//char arr[10] = { 0 };   //在栈空间上开辟10个连续空间


//    1. 为什么要动态内存分配
// 静态内存 的空间开辟是固定的，在使用是不能调整
// 引入动态内存开辟，可以自己 申请 和 释放 空间，就比较灵活了


//           一， 动态内存开辟函数
//malloc 负责申请内存  free  负责释放内存

// malloc函数
#include<stdlib.h>
//void* malloc(size_t size);        //size；要分配的内存的我字节数
//功能：向内存的堆区申请⼀块连续可⽤的空间，并返回指向这块空间的起始地址

//如果开辟成功，则返回这块空间的起始地址。
//如果开辟失败，则返回⼀个返回值的类型是NULL指针，因此malloc的返回值⼀定要做检查。
//返回值是void*，所以malloc函数并不知道开辟空间的类型，具体在使⽤的时候使⽤者
//
//int main()
//{
//	//int arr[] = { 1,2,3,4,5 }; //申请20个字节的空间 - 栈区
//	int* p = (int*)malloc(20); // 在堆区上申请20个字节的空间 - 堆区
//	//判断是非申请成功
//	if (p == NULL)
//	{
//		perror("use malloc");   //先打印括号里面的内容再打印错误信息
//		return 1;
//	}
//	//使用空间
//	for (int i = 0; i < 5; i++)
//	{
//		p[i] = i + 1;
//	}
// //释放内存
//	free(p);
//	p=NULL;
//
//	return 0;
//}



// free函数
//void free(void* ptr);

//功能：专⻔是⽤来做动态内存的释放和回收的
// 
//ptr:指向要释放的内存块的指针
//如果参数ptr指向的空间不是动态开辟的，那free函数的⾏为是未定义的。
//如果参数ptr是NULL指针，则函数什么事都不做



//   calloc 函数
//void* calloc(size_t num, size_t size);

//功能：函数的功能是为num个⼤⼩为size的元素开辟⼀块空间，并且把空间的每个字节初始化为0。
//与函数malloc的区别只在于calloc会在返回地址之前把申请的空间的每个字节初始化为0

//int main()
//{
//	//int arr[] = { 1,2,3,4,5 }; 
//	int* p = (int*)calloc(5,sizeof(int)); 
//	//判断是非申请成功
//	if (p == NULL)
//	{
//		perror("use malloc");  
//		return 1;
//	}
//	//使用空间
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", *(p+i));
//	}
// //释放内存
//	free(p);
//	p=NULL;
//
//	return 0;
//}



//realloc
//void* realloc(void* ptr, size_t size);

//ptr是要调整的内存地址
//size调整之后新⼤⼩，单位是字

//realloc函数可以做到对动态开辟内存⼤小进行调整


//int main()
//{
//	//int arr[] = { 1,2,3,4,5 }; 
//	int* p = (int*)calloc(5,sizeof(int)); 
//	//判断是非申请成功
//	if (p == NULL)
//	{
//		perror("use malloc");  
//		return 1;
//	}
//	//使用空间
//	for (int i = 0; i < 5; i++)
//	{
//		p[i] = i + 1;
//	}
//	//希望空间能放10个整形
//	int* ptr = (int*)realloc(p, 10 * sizeof(int));
//	if (ptr == NULL)
//	{
//		perror("use realloc");
//		return 1;
//	}
//	else
//	{
//		p = ptr;//继续使用p来维护空间
//		ptr = NULL;
//	}
//	//继续使用
//
//	//6 7 8 9 10
//	for (int i = 5; i < 10; i++)
//	{
//		p[i] = i + 1;
//	}
//	//释放空间
//	free(p);
//	p = NULL;
//	
//	return 0;
//}



//realloc调整有两种情况
//
//情况1:原有空间之后有足够大的空间是
//当是情况1的时候，要扩展内存就直接原有内存之后直接追加空间，原来空间的数据不发⽣变化。
//
//情况2：原有空间之后没有足够大的空间
//当是情况2的时候，原有空间之后没有⾜够多的空间时，扩展的⽅法是：在堆空间上另找⼀个合适⼤⼩
//的连续空间来使⽤。这样函数返回的是⼀个新的内存地址
/*会寻找新的满足要求的空间
将旧空间发的数据拷贝到新空间，保证数据不会丢失
释放旧空间，返回新空间的起始地址*/





//          二，常见的动态内存的错误

//2.1  对NULL指针的解引用操作
//void test()
//{
//	int* p = (int*)malloc(INT_MAX / 4);
//	*p = 20;//如果p的值是NULL，就会有问题
//	free(p);
//	p = NULL;
//}


//2.2 对动态开辟空间的越界访问
//void test()
//{
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		exit(EXIT_FAILURE);
//	}
//	for (i = 0; i <= 10; i++)
//	{
//		*(p + 1) = i;  //当i是10的时候越界访问
//	}
//	free(p);
//	p = NULL;
//}


//2.3 对非动态开辟内存使用free释放
//void test()
//{
//	int a = 10;  //栈区
//	int* p = &a;
//	free(p);   //free只能释放堆区
//}


//2.4 使用free释放一块动态开辟内存的一部分
//void test()
//{
//	int* p = (int*)malloc(100);
//	p++;
//	free(p);
//}



//2.5 对同一块动态内存多次释放
//void test()
//{
//	int* p = (int*)malloc(100);
//	free(p);
//	free(p);//重复释放
//}

//void test()
//{
//	int* p = (int*)malloc(100);
//	free(p);
//	p = NULL;
//	free(p);
//}
//int main()
//{
//	test();
//	return 0;
//}


//2.6 动态开辟内存忘记释放（内存泄露）
//void test()
//{
//	int* p = (int*)malloc(100);
//	if (NULL != p)
//	{
//		*p = 20;
//	}
//}
//int main()
//{
//	test();
//	//只用了4个字节的空间，其他的没有释放
//	while (1);
//	return 0;
//}
//动态开辟空间一定要释放，并且正确释放     malloc 和 free 成对使用
//如果不释放，也要给别人交代清楚




//            三 ， 动态内存经典笔试题分析
// 
//题目一

#include<string.h>
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);    //传入的是str的值NULL，实参没有变化，还是NULL
//	strcpy(str, "hello world");
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}


//修改一
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);    //实参没有变化，还是NULL
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//修改二
//char* GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory(str);    //传入的是str的值NULL，实参没有变化，还是NULL
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}



//题目二

//char* GetMemory(void)
//{
//	static char p[] = "hello world";       //p生命周期只在函数内
//	//延长生命周期
//	//1.static
//	//2.动态开辟
//		return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();       //地址传过来了但是无法打印   野指针
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}


//题目三

//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);  //没有释放动态空间
//	//补充
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}


//题目四

//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);     //野指针
//	//补充
//	str = NULL;
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}


//           四，柔性数组
//C99中，结构中的最后⼀个元素允许是未知⼤⼩的数组，这就叫做『柔性数组』成员


//柔性数组的特点（要求）

//1，结构中的柔性数组成员前⾯必须⾄少⼀个其他成员
//2，sizeof返回的这种结构⼤⼩不包括柔性数组的内存
//3，包含柔性数组成员的结构⽤malloc()函数进⾏内存的动态分配，并且分配的内存应该⼤于结构的⼤
//⼩，以适应柔性数组的预期⼤⼩。


//特点1
//struct st_type
//{
//	int i;
//	int a[0];  //柔性数组成员   有些编译器要去掉[]中的0
//};


//特点2
//struct st_type
//{
//	int i;
//	int a[0];
//};
//int main()
//{
//	printf("%zu\n", sizeof(struct st_type));
//}


//特点三  及使用
//struct S
//{
//	int n;
//	int arr[];//柔性数组成员，我希望arr开始的时候能存5个整形，后期arr空间大小可以调节
//};
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	if (ps == NULL)
//	{
//		perror("use malloc");
//		return 1;
//	}
//	ps->n = 100;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = 1 + i;     //在ps结构体指针中找到arr[]赋值
//	}
//	//扩容
//	struct S* ptr = (struct S*)realloc(ps, sizeof(struct S) + 10 * sizeof(int));
//	if (ptr == NULL)
//	{
//		perror("realloc");
//		return 1;
//	}
//	ps = ptr;
//	ptr = NULL;
//	for (i = 0; i < 10; i++)
//	{
//		ps->arr[i] = 1 + i;
//	}
//	//释放
//	free(ps);
//	ps = NULL;
//	return 0;
//}




//  c/c++程序内存分配的几个区域

//1. 栈区（stack）：在执⾏函数时，函数内局部变量的存储单元都可以在栈上创建，函数执⾏结束时
//这些存储单元⾃动被释放。栈内存分配运算内置于处理器的指令集中，效率很⾼，但是分配的内
//存容量有限。栈区主要存放运⾏函数⽽分配的局部变量、函数参数、返回数据、返回地址等。
//《函数栈帧的创建和销毁》
//2. 堆区（heap）：⼀般由程序员分配释放，若程序员不释放，程序结束时可能由OS（操作系统）
//回收。分配⽅式类似于链表。
//3. 数据段（静态区）：（static）存放全局变量、静态数据。程序结束后由系统释放。
//4. 代码段：存放函数体（类成员函数和全局函数）的⼆进制代码。