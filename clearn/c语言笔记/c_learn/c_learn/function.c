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
//	//Swap1(a, b);  //传值调用
//	//Swap2(&a, &b);  //传址调用
//	printf("交换后:a=%d b=%d\n",a, b);
//	return 0;
//}



//数组做函数参数
//void Print(int arr[], int x)
//{
//	for (x = 0; x < 3; x++)
//	{
//		printf("%d ", arr[x]);
//	}
//}
//int main()
//{
//	int arr[3] = { 1,2,3 };
//	Print(arr, 3);
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


//int main()
//{
//	printf("%d", printf("%d", printf("%d", 43)));   
//	//printf返回字符打印的个数     第一个printf返回43第二个printf返回2第三个printf返回1，输出结果为4321
//	return 0;
//}




//函数不写返回值的时候，默认返回类型时int
//ADD(int x, int y)
//{
//	return x + y;
//}
// 
// 
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = ADD(a, b);
//	printf("%d\n", c);
//	return 0;
//}


 


//                                       函数的声明和定义

//函数的声明               一般出现在函数的使用之前。要满足先声明后使用
//int ADD(int x,int y);
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	//加法
//	int sum = ADD(a, b);
//	printf("%d\n", sum);
//	return 0;
//}
//
////函数的定义
//int ADD(int x, int y)
//{
//	return x + y;
//}







//                                      函数的递归
// 1,递归必须存在限制条件，当满足这个限制条件的时候，递归便不再继续
//2，每次递归调用之后越来越接近这个限制条件



//1，接受一个整形值(无符号)，按顺序打印它的每一位
//例如：
//输入：1234，输出1，2，3，4

//void print(unsigned int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int main()
//{
//	unsigned int num = 0;    //unsigned int 是无符号整形
//	scanf("%u", &num);
//	////逆序
//	//while (num)    //当num等于0是不进入循环
//	//{
//	//	printf("%d ", num % 10);
//	//	num = num / 10;
//	//}
//	
//
//	//递归思路      用函数
//	print(num);
//	return 0;
//}





// 2，编写函数不允许创建临时变量，求字符串的长度
#include<string.h>
//int my_strlen(char str[])  //参数部分写出数组的形式
//int my_strlen(char*str)     //参数部分写出指针的性质
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;//找下一个字符
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abc";
//	int len = my_strlen(arr);
//	printf("%d ", len);
//	return 0;
//}




//sqrt函数    开平方
#include<math.h>
//int main()
//{
//	double ret;
//	ret = sqrt(16.0);
//	printf("%lf", ret);
//	return 0;
//}


//传地址 ，用指针接收
//void swap(int* px, int* py)
//{
//	int z = *px;
//	*px = *py;
//	*py = z;
//}
//int main()
//{
//	int a = 2;
//	int b = 3;
//	printf("交换前：%d %d", a, b);
//	swap(&a, &b);
//	printf("交换后：%d %d", a, b);
//	return 0;
//}



//计算单个阶乘的和
//int fac(int n)
//{
//	int sum1 = 0;
//	for (int j = 1; j <= n; j++)
//	{
//		int ret = 1;
//		for (int i = 1; i <= j; i++)
//		{
//			ret = ret * i;
//		}
//		sum1 = sum1+ret;
//	}
//	return sum1;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = fac(n);
//	printf("%d", sum);
//	return 0;
//}



//static 关键字    修饰局部变量  修饰全局变量
//局部变量用 static 后变成全局变量
//全局变量用 static 后限制只能在当前文件中使用时
//void tect()
//{
//	int j = 0;     //延长了生命周期  ，但没有改变其作用域
//	j++;
//	printf("%d ", j);
//}
//int main()
//{
//	for (int i = 0; i < 5; i++)
//	{
//		tect();
//	}
//	return 0;
//}




//实现函数判断year是不是润年。

//int year(int n)
//{
//	if (n % 4 == 0 && n % 100 == 0 || n % 400)
//	{
//		
//		return 1;
//	}
//	else
//	{
//		return 0;
//
//	}
//}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int b = year(a);
//	if (b == 1)
//	{
//		printf("%d是闰年\n", a);
//	}
//	else
//	{
//		printf("%d不是闰年\n", a);
//	}
//	return 0;
//}


//写一个二分查找函数

//int bin_search(int arr[], int left, int right, int key)
//{
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (key < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else if (key > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//
//	}
//	if (left > right)
//	{
//		return -1;
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9.10 };
//	int left = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int right = sz - 1;
//	int key = 7;
//	int ret = bin_search(arr, 0,sz-1, key);
//	if (ret != -1)
//	{
//		printf("找到了，下标是：%d", ret);
//
//	}
//	if (ret == -1)
//	{
//		printf("没有找到返回：-1");
//	}
//	return 0;
//}