#define _CRT_SECURE_NO_WARNINGS

#include "List.h"
#include "List.cpp"

int main()
{
	//初始化链表
	LNode* L = ListInit();
	//打印链表
	ListPrint( L);
	return 0;
}