#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//数组可以储存多个相同数据类型的元素
//一维数组
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

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%d\n", sizeof(arr));  //sizeof  求整个数组的字节大小
	int len = sizeof(arr) / sizeof(arr[0]);  //求数组的长度
	

	return 0;
}