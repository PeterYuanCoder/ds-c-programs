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

// 在链表的第i个下标位置插入元素x
void ListInsert(LNode* L, int i, LDataType x)
{
    assert(L);
    assert(i >= 0);
    LNode* i_1Node = L;  //从哨兵位结点开始
    int j = -1;
    while (j < i - 1 && i_1Node != NULL)
    {
        i_1Node = i_1Node->next;
        j++;
    }
    //没有i-1个结点说明非法
    assert(i_1Node != NULL);
    //插入新的结点
    LNode* newNode = BuyListNode(x);
    newNode->next = i_1Node->next;
    i_1Node->next = newNode;

}


// 删除链表中下标为i的结点，并用x带出结点的值
LDataType ListDelete(LNode* L, int i)
{
    assert(L);
    assert(i >= 0);
    int j = -1;
    LNode* i_1Node = L->next;
    while (j < i - 1 && i_1Node != NULL)
    {
        i_1Node = i_1Node->next;
        j++;
    }
    assert(i_1Node != NULL && i_1Node->next != NULL);
    LNode* iNode = i_1Node->next;
    i_1Node->next = iNode->next;
    LDataType x = iNode->data;
    free(iNode);
    iNode = NULL;
    return x;
}


//销毁链表
void ListDestroy(LNode* L)
{
    LNode* cur = L->next;   // cur指向第一个有效结点（跳过哨兵头结点）
    while (cur)             // cur != NULL，还有结点就循环
    {
        LNode* next = cur->next; // 先保存下一个结点地址！【重点】
        free(cur);               // 释放当前结点内存
        cur = next;              // cur跳到刚才保存好的下一个结点
    }
    free(L);  // 最后释放哨兵头结点
}
