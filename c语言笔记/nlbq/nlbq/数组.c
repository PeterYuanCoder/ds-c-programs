#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//数组可以储存多个相同数据类型的元素
//                                                    一维数组
//int main()
//{
//	int arr[6];     // []内只能是整数，不能用变量传值
//	int arr2[6] = { 12,12 };//局部初始化其余4个均为0
//	return 0;
//}


//迭代
//int main()
//{
//	int arr[6] = { 12,34,5,7,8,3 };
//	for (int i = 0; i < 6; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	return 0;
//}


//给数组输入元素
//int main()
//{
//	int arr[5];
//	for (int i = 0; i < 5; i++)
//	{
//		scanf("%d" ,&arr[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	return 0;
//}



//sizeof与数组

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%d\n", sizeof(arr));  //sizeof  求整个数组的字节大小
//	int len = sizeof(arr) / sizeof(arr[0]);  //求数组的长度
//	
//	return 0;
//}



//字符数组
//%s  打印遇到\0停止打印

//int main()
//{
//	char arr[] = { 'a','b','c','d' };
//	char arr1[] = "abcd";            //字符串数组  有一个\0
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int len1 = sizeof(arr1) / sizeof(arr1[0]);
//	printf("%d\n", len);
//	printf("%d\n", len1);
//	return 0;
//}


//把数组逆序

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	int j = len - 1;
//	while (i < j)
//	{
//		int tmp = arr[i];
//		arr[i] = arr[j];
//		arr[j]=tmp;
//		i++;
//		j--;
//	}
//	//printf("%d\n", arr);   数组不能直接打印
//	for (int p = 0; p < len; p++)
//	{
//		printf("%d ", arr[p]);
//	}
//	return 0;
//}





//数组元素扩大2倍

//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	//扩大2倍
//	for (int i = 0; i < len; i++)
//	{
//		arr[i] = arr[i] * 2;
//	}
//	//查看效果
//	for (int j = 0; j < len; j++)
//	{
//		printf("%d ", arr[j]);
//	}
//	return 0;
//}



//二分查找    必须是有序数组
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int k = 1;
//	int left = 0;
//	int right = len - 1;
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (k < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else if(k > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了，下标是：%d",mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到" );
//	}
//	return 0;
//}





//                                       二维数组             表格
//                      二维数组是特殊的一维数组
//int main()
//{
//	//什么都没定义值   值是随机的
//	int arr[2][3];
//	int arr1[] = { 1,2,3,4 };
//	int arr2[2][3] = { {1,2},{3,4,5} };//没有赋值的用0补
//	int arr3[2][3] = { 1,2,3,4,5,6 };     //2行3列
//	//在c语言中 的二维数组  是可以省略行的  但是不能省略列
//	int arr4[][3] = { 1,2,3,4,5,6 };
//	return 0;
//}




//元素输出 (迭代)  for循环的嵌套
//int main()
//{
//	int arr[2][3] = { 1,2,3,4,5,6 };
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}




//二维数组的元素输入
//int main()
//{
//	//输入元素
//	int arr[2][3];
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	//输出元素
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//				printf("%d ", arr[i][j]);
//		}
//			printf("\n");
//	}
//}





//作业
//将数组A中的内容和数组B中的内容进行交换。（数组一样大）

//int main()
//{
//	int A[] = { 1,2,3 };
//	int B[] = { 4,5,6 };
//	int c = 0;
//	int len = sizeof(A) / sizeof(A[0]);
//	//交换
//	for (int i = 0; i < len; i++)
//	{
//		c = A[i];
//		A[i] = B[i];
//		B[i] = c;
//	}
//	//查看数组A的元素变化
//	for (int j = 0; j < len; j++)
//	{
//		printf("%d ", A[j]);
//	}
//	printf("\n");
//	//查看数组B的元素变化
//	for (int n = 0; n < len; n++)
//	{
//		printf("%d ", B[n]);
//	}
//	return 0;
//}



//编写一个程序，从用户输入中读取10个整数并存储在一个数组中。然后，计算并输出这些整数的平均值。

//int main()
//{
//	int arr[10] = { 0 };
//	int sum = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		sum = sum + arr[i];
//	}
//	int ever = sum/10;
//	printf("%d", ever);
//	
//	return 0;
//}



//二维数组的转置
//int main()
//{
//	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			printf("%d", arr[i][j]);
//		}
//		printf("\n");
//	}
//	//开始交换
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = i+1; j < 3; j++)
//		{
//			int tmp = arr[i][j];
//			arr[i][j] = arr[j][i];
//			arr[j][i] = tmp;
//		}
//	}
//	printf("===================\n");
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			printf("%d", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
