#define _CRT_SECURE_NO_WARNINGS

#include"LinkStack.h"

// 初始化链式栈s
void LinkStackInit(LinkStack* s)
{
	assert(s);
	s->topHead = NULL;
	s->size = 0;
}


// 销毁链式栈s
void LinkStackDestroy(LinkStack* s)
{
	LNode* cur = s->topHead;
	while (cur)
	{
		LNode* next = cur->next;
		free(cur);
		cur = next;
	}
	s->size = 0;
	s->topHead = NULL;
}


// x入栈
void LinkStackPush(LinkStack* s, STDataType x)
{
	assert(s);
	LNode* newNode = (LNode*)malloc(sizeof(LNode));
	if (newNode == NULL)
	{
		perror("LinkStackPush()::malloc()");
		return;
	}
	newNode->data = x;

	newNode->next = s->topHead;
	s->topHead = newNode;

}

// 出栈，并返回栈顶元素
STDataType LinkStackPop(LinkStack* s)
{
	LNode* delNode = s->topHead;
	LNode* topE = delNode->data;
	s->topHead = delNode->next;
	free(delNode);
	delNode = NULL;
	return topE;
}

// 获取栈顶元素
STDataType LinkStackTop(LinkStack* s)
{
	return s->topHead->data;
}

// 获取栈中有效元素个数
int LinkStackSize(LinkStack* s)
{
	return s->size;
}

// 检测栈是否为空，如果是空返回真，否则返回假
bool LinkStackEmpty(LinkStack* s)
{
	return (s->size == 0);
}