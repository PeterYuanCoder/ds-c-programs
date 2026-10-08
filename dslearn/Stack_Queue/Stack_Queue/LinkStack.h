#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


typedef int STDataType;

//链式栈底层单链表中的结点定义
typedef struct LinkStackNode {
	struct LinkStackNode* next;
	STDataType data;
}LNode;


typedef struct {
	LNode* topHead;//栈顶结点指针
	int size;     //栈中数据个数
}LinkStack;



// 初始化链式栈s
void LinkStackInit(LinkStack* s);

// 销毁链式栈s
void LinkStackDestroy(LinkStack* s);

// x入栈
void LinkStackPush(LinkStack* s, STDataType x);

// 出栈，并返回栈顶元素
STDataType LinkStackPop(LinkStack* s);

// 获取栈顶元素
STDataType LinkStackTop(LinkStack* s);

// 获取栈中有效元素个数
int LinkStackSize(LinkStack* s);

// 检测栈是否为空，如果是空返回真，否则返回假
bool LinkStackEmpty(LinkStack* s);
