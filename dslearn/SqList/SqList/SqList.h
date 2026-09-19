#pragma once

// SqList.h — 一般这些接口函数声明放到.h中
// 下面的接口函数的实现放到SqList.cpp中
#include<stdbool.h>  // bool：声明EmptySqList的返回类型

// typedef是为了方便类型替换
typedef int SqDataType;  // 数据元素类型

typedef struct {
	SqDataType* arr;      // 存储数据的动态数组的指针
	int size;             // 记录顺序表中已经存入的数据个数
	int capacity;         // 动态数组的容量空间的大小
}SqList;

// 命名约定：下标从0开始；Back=尾部，Front=头部

// 初始化顺序表
void SqListInit(SqList* ps);

// 销毁顺序表
void SqListDestroy(SqList* ps);

// 返回顺序表中第i个下标位置元素的值
SqDataType GetElem(SqList* ps, int i);
// 修改顺序表中第 i 个位置元素的值
void SqListModify(SqList* ps, int i, SqDataType x);

// 返回第一个等于x的数据元素的下标，若不存在返回-1
int LocateElem(SqList* ps, SqDataType x);

// 在顺序表的第i个位置插入元素x（i可取0~size）
void SqListInsert(SqList* ps, int i, SqDataType x);

// 删除顺序表中第i个元素，并返回删除的值
SqDataType SqListDelete(SqList* ps, int i);

// 打印顺序表中的元素
void SqListPrint(SqList* ps);

// 检测顺序表是否为空，空返回true，否则返回false
bool EmptySqList(SqList* ps);

// 获取顺序表中有效元素个数
int SqListSize(SqList* ps);

// 尾插
void SqListPushBack(SqList* ps, SqDataType x);

// 头插
void SqListPushFront(SqList* ps, SqDataType x);

// 尾删
void SqListPopBack(SqList* ps);

// 头删
void SqListPopFront(SqList* ps);