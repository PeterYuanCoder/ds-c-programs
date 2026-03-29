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
//void Swap(int x, int y)
//{
//	//x和y是形参
//	int z;
//	z = x;
//	x = y;
//	y = z;
//
//}
//当实参传递给形参的时候，形参是实参的一份临时拷贝
//对形参的修改不会影响实参

//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	//交换
//	printf("交换前:a=%d b=%d\n",a, b);
//	//a和b叫实参
//	Swap(a, b);
//	printf("交换后:a=%d b=%d\n",a, b);
//
//	return 0;
//}



//int main()
//{
//	int a = 10;
//	int* p = &a;//指针
//	a = 20;//直接改
//	*p = 30;//间接该
//	return 0;
//
//}


//依次修改上面的代码
//void Swap(int* px, int* py)
//{
//	int z = *px;
//	*px = *py;
//	*py = z;
//}
//int Add(int x, int y)
//{
//	int z;
//	z = x + y;
//	return z;
//}
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	int c = Add(a, b);     //'当函数要改变a和b的值是要用取地址
//	printf("%d\n", c);
//	//交换
//	printf("交换前:a=%d b=%d\n",a, b);
//	//a和b叫实参
//	Swap(&a, &b);
//	printf("交换后:a=%d b=%d\n",a, b);
//	return 0;
//}



//         函数参数
// 1,形参只在函数范围内有效


//          函数的调用

//1，传值调用   形参和实参分别占有不同的内存块，对形参的修改不会影响实参
//2，传址调用   函数内部可以直接操作函数外部的变量
//void Swap(int* px, int* py)
//{
//	int z = *px;
//	*px = *py;
//	*py = z;
//}
//int Add(int x, int y)
//{
//	int z;
//	z = x + y;
//	return z;
//}
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	int c = Add(a, b);     //'当函数要改变a和b的值是要用取地址
//	printf("%d\n", c);
//	//交换
//	printf("交换前:a=%d b=%d\n",a, b);
//	//a和b叫实参
//	Swap1(a, b);  //传值调用
//	Swap2(&a, &b);  //传址调用
//	printf("交换后:a=%d b=%d\n",a, b);
//	return 0;
//}



//练习1.写一个函数可以判断一个数是不是素数
//打印100到200之间的素数
//素数是只能被1和他本身整除的数
//不是素数必定有一个是小于或等于它的开平方的因子

//1,循环
#include<math.h>
//sqrt是数学库函数
//开平方
//头文件  <math.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//
//	for (i = 100; i <= 200; i++)
//	{  
//		int flag = 1;
//	    int j = 0;
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//		{
//			flag = 0;
//			break;
//		}
//		}
//		
//		if (flag == 1)
//		{
//		count++;
//		printf("%d ", i);
//		}
//	}
//	printf("\ncount=%d\n", count);
//	return 0;
//}




//2.函数


//定义  是素数返回1   不是素数返回0
//int is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//
//}
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 101; i <= 200; i += 2)
//	{
//		if (is_prime(i))
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\ncount=%d\n",count);
//	return 0;
//}



//2.练习二 ，用一个函数来判断是否为闰年  
// 打印1000到2000年之间的闰年
//闰年判断规则
// 1，能被4整除，并且不能被100整除是闰年
//2.能被400整除是闰年是

//1，循环
//int main()
//{
//	int year = 0;
//	for (year = 1000;year<=2000;year++)
//	{
//		if (year % 4 == 0 && year % 100 != 0||year%400==0)
//		{
//			printf("%d ", year);
//		}
//	}
//	return 0;
//}

//2.函数
//是闰年返回1，非闰年返回0
//int is_leap_year(int y)    //函数用于判断闰年  函数功能尽量单一
//{
//	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)   //记得改成y
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	int year;
//	for(year = 1000; year <= 2000; year++)
//	{
//		if (is_leap_year(year))
//		{
//			printf("%d ", year);
//		}
//	}
//	return 0;
//}




//练习三,写一个函数，实现一个整形有序数组的二分查找。

//写函数之前先考虑函数怎么用
//int binary_search(int arr[], int k, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	
//	while (left <= right)
//	{
//		int mid = left+(right-left)/2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;//找到了返回下标
//		}
//	}
//	if (left > right)
//	{
//		return -1;
//	}
//	
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9.10 };
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//找到的话我返回下标   ，  找不到返回-1
//	int ret = binary_search(arr, k, sz);     //传入判断所需的条件
//	if (ret == -1)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了，下标是：%d\n", ret);
//	}
//	return 0;
//}



//练习四，写一个函数，每调用一次这个函数，就会将num的值增加1。
// 方法一
//void ADD(int* p)
//{
//	(*p)++;
//}
//int main()
//{
//	int num = 0;
//		ADD(&num);
//		printf("%d\n", num);
//	return 0;
//}
// 
//方法二   比较&和*p指针的用法  
//int ADD(int n)
//{
//	n++;
//}
//int main()
//{
//	int num = 0;
//	num = ADD(num);
//	printf("%d\n", num);
//	num = ADD(num);
//	printf("%d\n", num);
//	return 0;
//}





//                                    函数的嵌套调用和链式访问

//1，函数嵌套调用        函数可以嵌套调用，但是不能嵌套定义
//int new_line()
//{
//	printf("hehe\n");
//}
//int three_line()
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		new_line();
//	}
//}
//int main()
//{
//	three_line();
//	return 0;
//}


//2，链式访问
//int main()
//{
//	int len = strlen("abcdef");
//	printf("%d\n", len);
//	
//	//链式访问
//	printf("%d\n", strlen("abcdef"));   
//	return 0;
//}


int main()
{
	printf("%d", printf("%d", printf("%d", 43)));   
	//printf返回字符打印的个数     第一个printf返回43第二个printf返回2第三个printf返回1，输出结果为4321
	return 0;
}