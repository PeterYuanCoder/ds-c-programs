#define _CRT_SECURE_NO_WARNINGS
#include "SqList.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// 初始化顺序表
// 有些书本上的用法
// void SqListInit(SqList& s);
void SqListInit(SqList* ps)
{
	assert(ps);
	ps->arr = (SqDataType*)malloc(sizeof(SqDataType) * 4);
	if (ps->arr == 0)
	{
		printf("SqListInit:申请空间失败\n");
	}
	ps->size = 0;
	ps->capacity = 4;
}

//判断是否需要扩容
static void SqListCheckCapacity(SqList* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{

		SqDataType* tmp = (SqDataType*)realloc(ps->arr, sizeof(SqDataType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			printf("SqListCheckCapacity:空间申请失败\n");
			return;
		}
		ps->arr = tmp;
		ps->capacity *= 2;
	}
}

// 销毁顺序表
void SqListDestroy(SqList * ps)
{
	assert(ps);
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}

// 返回顺序表中第i个下标位置元素的值
SqDataType GetElem(SqList* ps, int i)
{
	assert(ps);
	assert(i >= 0 && i < ps->size);
	return ps->arr[i];
}
// 修改顺序表中第 i 个位置元素的值
void SqListModify(SqList* ps, int i, SqDataType x)
{
	assert(ps);
	assert(i >= 0 && i < ps->size);
	ps->arr[i] = x;
}

// 返回第一个等于x的数据元素的下标，若不存在返回-1
int LocateElem(SqList* ps, SqDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}

// 在顺序表的第i个位置插入元素x（i可取0~size）
void SqListInsert(SqList* ps, int i, SqDataType x)
{
	assert(ps);
	assert(i >= 0 && i <= ps->size);
	SqListCheckCapacity(ps);
	for (int j = ps->size - 1; j >= i; j--)
	{
		ps->arr[j + 1] = ps->arr[j];
	}
	ps->arr[i] = x;
	ps->size++;
}

// 删除顺序表中第i个元素，并返回删除的值
SqDataType SqListDelete(SqList* ps, int i)
{
	assert(ps);
	assert(i >= 0 && i < ps->size);
	//再还没有删除之前先存起来，返回时直接使用。
	SqDataType x = ps->arr[i];
	for (int j = i + 1; j < ps->size; j++)
	{
		ps->arr[j - 1] = ps->arr[j];
	}
	ps->size--;
	return x;
}

// 打印顺序表中的元素
void SqListPrint(SqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

// 检测顺序表是否为空，空返回true，否则返回false
bool EmptySqList(SqList* ps)
{
	assert(ps);
	if (ps->size == 0)
	{
		return true;
	}
	return false;
}

// 获取顺序表中有效元素个数
int SqListSize(SqList* ps)
{
	assert(ps);
	return ps->size;
}

// 尾插
void SqListPushBack(SqList* ps, SqDataType x)
{
	assert(ps);
	SqListCheckCapacity(ps);
	ps->arr[ps->size] = x;
	ps->size++;
}

// 头插
void SqListPushFront(SqList* ps, SqDataType x)
{
	assert(ps);
	SqListCheckCapacity(ps);
	for (int i = ps->size - 1; i >= 0; i--)
	{
		ps->arr[i + 1] = ps->arr[i];
	}
	ps->arr[0] = x;
	ps->size++;
}

// 尾删
void SqListPopBack(SqList* ps)
{
	assert(ps);
	ps->size--;
}

// 头删
void SqListPopFront(SqList* ps)
{
	assert(ps);
	for (int i = 1; i < ps->size; i++)
	{
		ps->arr[i - 1] = ps->arr[i];
	}
	ps->size--;
}