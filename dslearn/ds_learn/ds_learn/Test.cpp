#define _CRT_SECURE_NO_WARNINGS
#include"SqList.h"

int main()
{
	//创建结构体变量
	SqList s1;
	//初始化
	SqListInit(&s1);
	//尾插
	SqListInsert(&s1, 0, 1);
	SqListInsert(&s1, 1, 2);
	SqListInsert(&s1, 2, 3);
	SqListPrint(&s1);

	//头插
	SqListInsert(&s1, 0, 100);
	SqListPrint(&s1);

	//中间插入
	SqListInsert(&s1, 1, 200);
	SqListPrint(&s1);
	//销毁结构体变量
	SqListDestroy(&s1);
	return 0;
}