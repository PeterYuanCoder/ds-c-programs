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

//模拟使用
//int main()
//{
//    int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//    int arr2[10] = { 0 };
//    memcpy(arr2, arr1, 20);
//    int i = 0;
//    for (i = 0; i < 10; i++)
//    {
//        printf("%d ", arr2[i]);
//    }
//    return 0;
//}



//memmove函数
//可以处理内存重叠的情况
// 
//void* memmove(void* destination, const void* source, size_t num);

//void* memmove(void* dst, const void* src, size_t count)
//{
//    void* ret = dst;
//    if (dst <= src || (char*)dst >= ((char*)src + count)) 
//    {
//        //前-》后
//        while (count--) {
//            *(char*)dst = *(char*)src;
//            dst = (char*)dst + 1;
//            src = (char*)src + 1;
//        }
//    }
//    else
//    {
//        //后-》前
//        dst = (char*)dst + count - 1;
//        src = (char*)src + count - 1;
//        while (count--) {
//            *(char*)dst = *(char*)src;
//            dst = (char*)dst - 1;
//            src = (char*)src - 1;
//        }
//    }
//    return(ret);
//}
//
//
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


//memset函数
//memset函数是⽤来设置内存块的内容的，将内存中指定⻓度的空间设置为特定的内容。

//int main()
//{
//	char arr[] = "hello world";
//	memset(arr, 'x', 5);
//	printf("%s\n", arr);
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5 };  //以字节为单位，1个整形4个字节
//	memset(arr, 1, 4);
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//memcmp函数
// 
// ⽐较指定的两块内存块的内容，⽐较从ptr1和ptr2指针指向的位置开始，最多比到向后的num个字节
// 
//int memcmp(const void* ptr1, const void* ptr2, size_t num);

//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,3,44,5 };
//	int r = memcmp(arr1, arr2, 16);     //arr1<arr2  返回 <0的值
//	printf("%d\n", r);
//	return 0;
//}

