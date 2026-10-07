#define _CRT_SECURE_NO_WARNINGS
#include"SeqStack.h"

//栈的初始化
void StackInit(Stack* s)
{
	assert(s);
	s->arr = (STDataType*)malloc(4 * sizeof(STDataType));
	if (s->arr == NULL)
	{
		perror("StackInit()::malloc()");
		return;
	}
	s->top = 0;
	s->capacity = 4;
}


// 栈的销毁
void StackDestroy(Stack* s)
{
	assert(s);
	if (s->arr == NULL)
	{
		return;
	}
	free(s->arr);
	s->arr = NULL;
	s->capacity = 0;
	s->top = 0;
}


// x元素⼊栈(进栈)
void StackPush(Stack* s, STDataType x)
{
	assert(s);
	assert(StackEmpty != NULL);

	//满了
	if (s->top == s->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(s->arr, sizeof(STDataType) * s->capacity * 2);
		if (tmp == NULL)
		{
			perror("StackPush()::realloc()");
			return;
		}
		s->arr = tmp;
		s->capacity *= 2;
	}
	//未满
	s->arr[s->top] = x;
	s->top++;
}


// 将栈顶元素出栈，并⽤返回栈顶元素
STDataType StackPop(Stack* s)
{
	assert(s);
	assert(StackEmpty != NULL);
	STDataType x = s->arr[s->top - 1];
	s->top--;
	return x;
}

// 获取栈顶元素并返回
STDataType StackTop(Stack* s)
{
	assert(s);
	assert(StackEmpty != NULL);
	return s->arr[s->top - 1];
}


//获取栈中有效元素个数
int StackSize(Stack* s)
{
	assert(s);
	return s->top;
}

//检测栈是否为空，如果是空返回真，否则返回假
bool StackEmpty(Stack* s)
{
	assert(s);
	if (s->top = 0)
	{
		return false;
	}
	return true;
}