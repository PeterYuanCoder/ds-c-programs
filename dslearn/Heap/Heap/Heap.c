#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"

//默认初始化堆
void HeapInit(Heap* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}

//封装一个专门用来交换的函数
void Swap(int* x, int* y)
{
	assert(x != NULL && y != NULL);
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//向上调整算法
void AdjustUp(HeapDataType* a,int child)
{
	assert(a);
	//双亲
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			//交换
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//堆的插入
void HeapPush(Heap* hp, HeapDataType x)
{
	assert(hp);
	if (hp->capacity == hp->size)   //堆为空
	{
		//开辟空间
		int newCapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HeapDataType* tmp = (HeapDataType*)realloc(hp->a, sizeof(HeapDataType) * newCapacity);
		if (tmp == NULL)
		{
			perror("HeapPush::realloc()");
			return;
		}
		hp->a = tmp;
		hp->capacity = newCapacity;
	}
	hp->a[hp->size] = x;
	hp->size++;

	AdjustUp(hp->a, hp->size - 1);
}

void AdjustDown(HeapDataType* a, int size, int parent)
{
	assert(a);
	//默认child为左孩子
	int child = parent * 2 + 1;
	while (child<size) 
	{
		//选出小的那个孩子
		if (child+1<size && a[child + 1] < a[child])
		{
			child++;
		}

		//比较小的孩子跟父亲比较
		if (a[child] < a[parent])
		{
			//交换父亲和孩子
			Swap(&a[child], &a[parent]);
			//父亲到孩子的位置上来
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// 堆的删除，删除堆顶数据
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);
	//交换堆顶和堆尾的数据位置
	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;

	//向下调整算法
	AdjustDown(hp->a, hp->size,0);
}

// 获取堆顶数据
HeapDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(hp->a);
	
	return hp->a[0];
}



//给一组数据，让你建堆
void HeapInitArray(Heap* hp, HeapDataType* a, int n)
{
	assert(hp);
	assert(a);
	assert(n > 0);

	hp->a = (HeapDataType*)malloc(sizeof(HeapDataType) * n);
	if (hp->a == NULL)
	{
		perror("HeapInitArray::malloc()");
		exit(-1);
	}
	memcpy(hp->a, a, sizeof(HeapDataType) * n);
	hp->size = hp->capacity = n;


	//向下调整     找到最后一个非叶子（叶子的双亲）
	for (int i = (n - 1 - 1) / 2; i >= 0 ; i--)
	{
		AdjustDown(hp->a, n, i);
	}
}



//堆排序
void HeapSort(int* a, int n)
{
	//升序，建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i++)
	{
		AdjustDown(a, n, i);
	}
	//选数排序
	int j = 1;  //选第几大的数
	while (j < n)     //当j等于n时，只有一个元素了
	{
		Swap(&a[0], &a[n - j]);
		AdjustDown(a, n - j, 0);
		j++;
	}

}


// 判空
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}


//堆的销毁
void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}


//获取堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}
