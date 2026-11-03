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
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
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


//冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		//单趟冒泡排序
		int flag = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

//挖空法
int PartitionDigHole(int* a, int left, int right)
{
	int pivotkeyi = a[left];
	while (left < right)
	{
		//从左边找小的，来填右边的位置（pivotkeyi）
		while (left < right && a[right] >= pivotkeyi)
		{
			right--;
		}
		//找到了,替换位置
		a[left] = a[right];
		//从右边找大的，来填左边的位置
		while (left < right && a[left] <= pivotkeyi)
		{
			left++;
		}
		//找到了，替换位置
		a[right] = a[left];
	}
	//将基准值放到相遇的位置
	a[left] = pivotkeyi;
	//返回相遇的位置的坐标
	return left;
}


//Lumoto的单趟划分
int PartitionLomuto(int* a, int left, int right)
{
	int pivotkeyi = a[right];
	int cur = left;
	int prev = left - 1;
	while (cur < right)
	{
		if (a[cur] <= pivotkeyi)
		{
			prev++;
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[prev + 1], &a[right]);
	return prev + 1;
}


void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return -1;
	}
	//找基准值，确定基准值的位置
	int pivotkeyi = PartitionLomuto(a, left, right);
	//int pivotkeyi = PartitionDigHole(a, left, right);

	//递归
	//左区间
	QuickSort(a, left, pivotkeyi - 1);
	//右区间
	QuickSort(a, pivotkeyi + 1, right);

}


//计数排序
void CountSort(int* a, int n)
{
	//遍历一遍选出最大和最小的值
	int min = a[0];
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	int range = max - min + 1;
	//开辟数组空间来计数
	int* count = (int*)calloc(range, sizeof(int));
	if (count == NULL)
	{
		perror("calloc::count()");
		return;
	}
	//统计次数
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	//count[i]记录<=映射值x的个数
	for (int i = 1; i < range; i++)
	{
		//当前位置等于前面次数的累加和
		count[i] += count[i - 1];
	}

	//开辟空间来存放数据，然后将这个数组拷贝回原数组即可
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc()::tmp()");
		return;
	}
	//存放数据，从后往前处理，确保稳定性
	for (int i = n - 1; i >= 0; i--)
	{
		tmp[count[a[i] - min] - 1] = a[i];
		count[a[i] - min]--;
	}
	//拷贝
	memcpy(a, tmp, sizeof(int) * n);

	//释放
	free(count);
	free(tmp);
}