#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


//                                             指针初识
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	printf("%d\n", a);
//	printf("%d\n", *p);   //*p解引用   间接访问&a这个地址所表示的内存
//	
//	*p = 100;
//	
//	printf("%d\n", a);
//	printf("%d\n", *p);
//
//	return 0;
//}



//int main()
//{
//	//在指针当中，指针的大小和指针的类型没有关系和操作系统是多少位有关系   32位：4   64位：8
//	//指针在间接访问的时候访问几个字节？取决于指针的类型！
//	printf("%zd\n", sizeof(char*));
//	printf("%zd\n", sizeof(short*));
//	printf("%zd\n", sizeof(int*));
//	printf("%zd\n", sizeof(double*));
//	return 0;
//}



//指针运算
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = &arr[0];     //数组是什么类型   指针就要是什么类型
//	//printf("%d\n", p);
//	//printf("%d\n", p+1);   //因为p是int类型所以+1是加4个字节   指针+整数加几个字节和指针类型相关
//
//	printf("p+1=%p\n", p + 1);
//	printf("&arr[1]=%p\n", &arr[1]);
//
//	printf("*(p+1)=%d\n", *(p + 1));
//	printf("arr[1]=%d\n", arr[1]);
//
//	return 0;
//}




//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = &arr[0];
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d\n", *(p + i));
//		printf("%d\n", p[i]);   //[i]  相当于*(数组名+i)    
//		//数组名  =  元素首元素的地址   
//		//1.sizeof(arr)在定义数组的同一个位置这个代表整个数组的字节大小
//		//2.&arr代表整个数组的地址
//	   
//	}
//	return 0;
//}


//指针-指针=元素个数
//前提：两个指针的类型是一样的且两个指针指向的是同一个内存
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p1 = &arr[2];
//	int* p2 = &arr[4];
//	printf("%d", p2 - p1);
//	return 0;
//}



//指针的关系运算
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = &arr[0];
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	while (p < arr + sz)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	return 0;
//}



//                                                   指针进阶

//const修饰   
//const修饰必须进行初始化 
//被修饰之后，在语法是加了限制，无法直接修改n  ,但n属性还是变量
//如果绕过n,使用n的地址，去修改能做到
//int main()
//{
//	const int a = 10;
//	//通过指针修改b
//	const int b = 10;   //修饰的是*b
//	int* pb = &b;
//	*pb = 99;
//	printf("%d\n", b);
//	printf("%d\n", *pb);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 10;
//	//const修饰pb ,pb的值指向&b不能改变 ，但是*p能变
//	int* const pb = &b;
//	*pb = 99;
//	return 0;
//
//}



//assert 断言
// 我们可以用它检查一个指针是否是NULL
// #include<assert.h>
// 
//int main()
//{
//	int* p = NULL;
//	//断言只能在debug情况下有效
//	assert(*p != NULL);
//	//
//	if (*p == NULL)
//	{
//		printf("当前指针为空\n");
//		return -1;
//	}
//	*p = 100;
//	return 0;
//}



//野指针
//指针指向的位置未知

//1.指针未初始化
//int main()
//{
//	int* p;
//	*p = 10;
//	return 0;
//}

//2.指针的越界访问
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = &arr[0];
//	int i = 0;
//	for (i = 0; i <= 11; i++)
//	{
//		//当指针超出指向范围时，p就是野指针
//		*(p++) = i;
//	}
//	return 0;
//}


//指针指向的空间释放

//int* text()  //n是整形 返回&n用int*返回
//{
//	int n = 100;   //可以用static修饰延长生命周期
//	return &n;  //n局部变量在函数结束是销毁，返回的地址是无效的
//}
//
//int main()
//{
//	int* p = test();
//	printf("%d\n", *p);
//	return 0;
//}