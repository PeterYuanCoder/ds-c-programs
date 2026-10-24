#define _CRT_SECURE_NO_WARNINGS

#include"sort.h"

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