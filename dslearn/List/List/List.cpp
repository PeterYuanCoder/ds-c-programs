#define _CRT_SECURE_NO_WARNINGS
#include "List.h"


LNode* BuyListNode(int data)
{
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    if (newNode == NULL)
    {
        printf("BuyListNode:申请空间失败\n");
    }
    //申请成功之后，对数据域和指针域进行初始化
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//初始化
LNode* ListInit()
{
	LNode* node = BuyListNode(-1);
	return node;
}

//打印链表
void ListPrint(LNode* L)
{
    assert(L);
    printf("头结点->");
    LNode* cur = L->next;//存头结点的地址
    while (cur == NULL)//最后都会返回为NULL
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("NULL");
}

// 获取链表中有效元素个数
int ListSize(LNode* L)
{
    assert(L);
    int size = 0;
    LNode* cur = L->next;
    while (cur == NULL)
    {
        cur = cur->next;
        size++;
    }
    return size;
}


//查找
//按值查找    返回地址
LNode* ListLocateElem(LNode* L, LDataType x)
{
    assert(L);
    LNode* cur = L->next;
    while (cur == NULL)
    {
        if (cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

//按位查找   返回地址
LNode* ListGetElem(LNode* L, int i)
{
    assert(L);
    assert(i >= 0);
    int j = 0;
    LNode* iNode = L->next;
    while (j < i && iNode!=NULL)
    {
        iNode = iNode->next;
        j++;
    }
    return iNode;
}