#define _CRT_SECURE_NO_WARNINGS
#include "DCList.h"

//创建一个新结点
DCListNode* BuyDCListNode(int data)
{
    DCListNode* newNode = (DCListNode*)malloc(sizeof(DCListNode));
    if (newNode == NULL)
    {
        printf("BuyListNode:申请空间失败\n");
    }
    //申请成功之后，对数据域和指针域进行初始化
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

//初始化
DCListNode* DCListInit()
{
    DCListNode* L = BuyDCListNode(-1);
    L->next = L;
    L->prev = L;
    return L;
}

// 销毁链表

//并不需要分两种来释放，都是同一个结点

void DCListDestroy(DCListNode* L)
{
    assert(L);
    DCListNode* cur = L->next;//我们必须是从第一个结点开始，不然循环条件进不去
    while (cur != L)
    {
        //存下一个结点的地址
        DCListNode* next = cur->next;
        free(cur);
        cur = next;
    }
    free(L);
}

// 获取链表的下标i的结点
DCListNode* DCListGetElem(DCListNode* L, int i)
{


}
