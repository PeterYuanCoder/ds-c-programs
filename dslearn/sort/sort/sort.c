#define _CRT_SECURE_NO_WARNINGS

#include"sort.h"


//交换函数
void Swap(int* x, int* y)
{
	int* tmp = *x;
	*x = *y;
	*y = tmp;
}



//直接插入排序

//类比我们抓扑克牌，新抓的一张，往前排序

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int end = i;
		//单趟
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;

			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
	
}


//希尔排序
void ShellSort(int* a, int n)
{
	int d = n;
	while (d > 1)
	{
		d = d / 3 + 1;//缩小增量
		//d组并行
		for (int i = 0; i < n - d; i++)
		{
			int end = i;
			int tmp = a[end + d];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + d] = a[end];
					end -= d;
				}
				else
				{
					break;
				}
			}
			a[end + d] = tmp;
		}
	}
}


//简单选择排序
void SelectSort(int* a, int n)
{
	//每次选出最小的或者选出最大的
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i; j < n ; j++)
		{
			if (a[min] > a[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			Swap(&a[min], &a[i]);
		}
	}
}