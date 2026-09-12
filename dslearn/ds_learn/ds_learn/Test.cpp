#define _CRT_SECURE_NO_WARNINGS
#include"SqList.h"

int main()
{
	//创建结构体变量
	SqList s1;
	//初始化
	SqListInit(&s1);
	//销毁结构体变量
	SqListDestroy(&s1);
	return 0;
}