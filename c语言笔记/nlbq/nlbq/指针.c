#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

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




int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = &arr[0];
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", *(p + i));
		printf("%d\n", p[i]);   //[i]  相当于*(数组名+i)    
		//数组名  =  元素首元素的地址   
		//1.sizeof(arr)在定义数组的同一个位置这个代表整个数组的字节大小
		//2.&arr代表整个数组的地址
	   
	}
	return 0;
}

int main()
{
	return 0;
}