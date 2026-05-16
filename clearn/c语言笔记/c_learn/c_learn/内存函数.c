#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//memcpy函数
// 
// 完成内存块拷贝,不关注内存中存放的数据是啥   strncpy只能拷贝字符串
// 只处理没有内存重叠的情况
// 
//void* memcpy(void* destination, const void* source, size_t num);

#include<string.h>

//void* my_memcpy(void* dst, const void* src, size_t count)
//{
//	void* ret = dst;
//	assert(dst);
//	assert(src);
//	while (count--) {
//		*(char*)dst = *(char*)src;
//		dst = (char*)dst + 1;
//		src = (char*)src + 1;
//	}
//	return(ret);
//}
//
//int main() 
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[20] = { 0 };
//	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
//	my_memcpy(arr2, arr1+2, 20);    //+2表示从3开始拷贝    数组的运算
//	for (int i = 0; i < sz2; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//
//}


//memmove函数
//可以处理内存重叠的情况
// 
//void* memmove(void* destination, const void* source, size_t num);


//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	memmove(arr1+2, arr1, 20);			
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}