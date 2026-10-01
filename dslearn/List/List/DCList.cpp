#define _CRT_SECURE_NO_WARNINGS
#include "DCList.h"

//创建一个新结点
DCListNode* BuyDCListNode(int data)
{
    DCListNode* newNode = (DCListNode*)malloc(sizeof(DCListNode));
    if (newNode == NULL)
    {
        //申请失败后就直接返回，绝不能再往下走，否则下一行就是对NULL解引用
        printf("BuyDCListNode:申请空间失败\n");
        return NULL;
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
    assert(L);
    //空的循环链表：头结点的后继和前驱都指向自己
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
// 位序从0开始；空链表或下标越界返回NULL
DCListNode* DCListGetElem(DCListNode* L, int i)
{
    assert(L);
    assert(i >= 0);
    int j = 0;
    DCListNode* cur = L->next;//从头结点的后继开始走
    //循环链表没有NULL作为结束标志，只能靠"走回头结点"来发现越界
    while (j < i && cur != L)
    {
        cur = cur->next;
        j++;
    }
    if (cur == L)
    {
        //两种情况都到这里：链表本来是空的，或者下标i超出了实际长度
        return NULL;
    }
    return cur;
}

// 在pos位置后插入值为x的结点
void DCListInsert(DCListNode* pos, DCLDataType x)
{
    assert(pos);
    DCListNode* newNode = BuyDCListNode(x);
    assert(newNode);
    //把新结点挂到 pos 和 pos->next 之间，三步的顺序不能颠倒：
    //第②步要用到pos->next的"原值"，所以必须排在第③步之前
    newNode->prev = pos;
    newNode->next = pos->next;      //① 先记住pos原来的后继
    pos->next->prev = newNode;      //② 此时pos->next还是原后继，把它回指给新结点
    pos->next = newNode;            //③ 最后才改pos的后继
    //传入pos == L（头结点）即为头插；传入pos == L->prev（尾结点）即为尾插
    //这两种特例不需要额外分支，指针操作天然兼容
}

// 删除pos位置的结点
// 注意：禁止传入头结点L，本接口拿不到L，无法自行校验，误传会破坏循环使后续遍历全部死循环
void DCListDelete(DCListNode* pos)
{
    assert(pos);
    //摘链：让pos的前驱和后继互相跨过pos
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    free(pos);
}

// 头插
void DCListPushFront(DCListNode* L, DCLDataType x)
{
    assert(L);
    //头结点之后插入 == 头插，与单链表里"遍历到尾再插"的写法相比是O(1)
    DCListInsert(L, x);
}

// 尾插
void DCListPushBack(DCListNode* L, DCLDataType x)
{
    assert(L);
    DCListNode* newNode = BuyDCListNode(x);
    assert(newNode);
    //双链表的优势在这里：直接从L->prev（尾结点）接上，不需要像List.cpp的尾插那样先遍历一遍
    newNode->next = L;             //① 循环的"出口"永远回到头结点
    newNode->prev = L->prev;
    L->prev->next = newNode;      //② 让原来的尾结点后继指向新结点
    L->prev = newNode;             //③ 让头结点的前驱指向新结点
}

// 头删
void DCListPopFront(DCListNode* L)
{
    assert(L);
    assert(L->next != L);// 空链表不能头删
    DCListDelete(L->next);
}

// 尾删
void DCListPopBack(DCListNode* L)
{
    assert(L);
    assert(L->prev != L);// 空链表不能尾删
    DCListDelete(L->prev);
}

// 打印链表中的元素（正向 + 反向，便于验证前驱指针是否正确）
void DCListPrint(DCListNode* L)
{
    assert(L);
    DCListNode* cur = L->next;
    printf("正向：头结点");
    while (cur != L)
    {
        printf("->%d", cur->data);
        cur = cur->next;
    }
    printf("->头结点\n");

    //借助prev指针从尾结点倒着走一遍，这是单链表做不到的
    cur = L->prev;
    printf("反向：头结点");
    while (cur != L)
    {
        printf("->%d", cur->data);
        cur = cur->prev;
    }
    printf("->头结点\n");
}