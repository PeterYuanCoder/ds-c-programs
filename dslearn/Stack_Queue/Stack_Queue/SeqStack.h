#pragma once

#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>


typedef int STDataType;
typedef struct
{
	STDataType* arr;//执行栈数组空间的指针
	int top;      //执行栈顶
	int capacity;  //容量
}Stack;


//栈的初始化
void StackInit(Stack* s);

// 栈的销毁
void StackDestroy(Stack* s);

// x元素⼊栈(进栈)
void StackPush(Stack* s, STDataType x);

// 将栈顶元素出栈，并⽤返回栈顶元素
STDataType StackPop(Stack* s);

// 获取栈顶元素并返回
STDataType StackTop(Stack* s);

//获取栈中有效元素个数
int StackSize(Stack* s);

//检测栈是否为空，如果是空返回真，否则返回假
bool StackEmpty(Stack* s);