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
//		p[i] = i + 1;
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