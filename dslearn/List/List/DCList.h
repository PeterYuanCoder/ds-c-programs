#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DCLDataType;
typedef struct DCListNode {
	DCLDataType data;          // 存储数据元素的值
	struct DCListNode* prev;   // 存放前驱结点的指针
	struct DCListNode* next;   // 存放后继结点的指针
}DCListNode;

// 创建一个新结点（申请失败返回NULL）
DCListNode* BuyDCListNode(int data);

// 链表初始化
DCListNode* DCListInit();

// 销毁链表（连头结点一起释放）
void DCListDestroy(DCListNode* L);

// 获取链表的位序i的结点：位序从0开始，空链表或下标越界返回NULL
DCListNode* DCListGetElem(DCListNode* L, int i);

// 在pos位置后插入值为x的结点
// 传入pos为头结点L则等价于头插，传入pos为L->prev则等价于尾插
void DCListInsert(DCListNode* pos, DCLDataType x);

// 删除pos位置的结点
// 禁止传入头结点L：本接口拿不到L，无法自行校验，误传会破坏循环使后续遍历死循环
void DCListDelete(DCListNode* pos);

// 头插
void DCListPushFront(DCListNode* L, DCLDataType x);

// 尾插（O(1)，直接从L->prev接上）
void DCListPushBack(DCListNode* L, DCLDataType x);

// 头删（空链表不可调用）
void DCListPopFront(DCListNode* L);

// 尾删（空链表不可调用）
void DCListPopBack(DCListNode* L);

// 打印链表中的元素（正向 + 反向）
void DCListPrint(DCListNode* L);