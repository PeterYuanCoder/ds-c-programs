#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//strcpy函数  
//拷贝 后面的拷贝到前面的
//int main()
//{
//	char arr1[] = { 0 };
//	char arr2[] = "hello bit";
//	strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}



//memset函数
//int main()
//{
//	char arr[] = "hello bit";
//	memset(arr, 'x', 5);     //将arr中的前五个字节换成x
//	printf("%s\n", arr);
//	return 0;
//}



//自定义函数
//函数的定义

// 写一个函数返回两个数的最大值
//int get_max(int a,int b)   //int 表示返回整形，void 表示不用返回
//{
//	return (a > b ? a : b);
//}
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	//求最大值
//	//函数的调用     没说；一定要用这个名字
//	int m=get_max(a, b);
//	printf("%d", m);
//	return 0;
//}




//写一个函数可以交换两个整形变量
void Swap(int a, int b)
{
	int z;
	z = a;
	a = b;
	b = z;

}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	//交换
	printf("交换前：a=%d b=%d\n".a, b);
	Swap(a, b);
	printf("交换后：a=%d b=%d\n".a, b);

	return 0;
}