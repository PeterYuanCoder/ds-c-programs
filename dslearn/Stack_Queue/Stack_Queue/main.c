#define _CRT_SECURE_NO_WARNINGS

//#include"SeqStack.h"
//
//int main() {
//    Stack s;
//
//    //初始化
//    StackInit(&s);
//
//    // 入栈，检测栈顶数据元素 和 栈中有效数据元素是否正确
//    StackPush(&s, 1);
//    StackPush(&s, 2);
//    StackPush(&s, 3);
//    StackPush(&s, 4);
//    StackPush(&s, 5);
//
//    //printf("栈中元素总数为: %d\n", StackSize(&s));
//    printf("栈顶元素为: %d\n", StackTop(&s));
//
//    // 出栈
//    printf("出栈: 栈顶元素为: %d\n", StackPop(&s));
//    printf("出栈: 栈顶元素为: %d\n", StackPop(&s));
//    printf("出栈: 栈顶元素为: %d\n", StackPop(&s));
//    printf("出栈: 栈顶元素为: %d\n", StackPop(&s));
//    printf("出栈: 栈顶元素为: %d\n", StackPop(&s));
//
//    // 断言报错
//    //printf("出栈: 栈顶元素为: %d\n", StackPop(&s));
//    //printf("栈顶元素为: %d\n", StackTop(&s));
//
//    StackPush(&s, 6);
//    StackPush(&s, 7);
//
//    // 出栈
//    printf("出栈: 栈顶元素为: %d\n", StackPop(&s));
//    printf("出栈: 栈顶元素为: %d\n", StackPop(&s));
//
//    StackDestroy(&s);
//
//    return 0;
//}




#include"LinkStack.h" 

int main() {
	LinkStack s;
	LinkStackInit(&s);

	// 入栈，检测栈顶数据元素 和 栈中有效数据元素是否正确
	LinkStackPush(&s, 1);
	LinkStackPush(&s, 2);
	LinkStackPush(&s, 3);
	printf("出栈: 栈顶元素为: %d\n", LinkStackPop(&s));
	printf("出栈: 栈顶元素为: %d\n", LinkStackPop(&s));

	LinkStackPush(&s, 4);
	LinkStackPush(&s, 5);
	printf("栈中元素总数为: %d\n", LinkStackSize(&s));
	printf("栈顶元素为: %d\n", LinkStackTop(&s));

	// 出栈
	printf("出栈: 栈顶元素为: %d\n", LinkStackPop(&s));
	printf("出栈: 栈顶元素为: %d\n", LinkStackPop(&s));
	printf("出栈: 栈顶元素为: %d\n", LinkStackPop(&s));
	//printf("出栈: 栈顶元素为: %d\n", LinkStackPop(&s));
	//printf("出栈: 栈顶元素为: %d\n", LinkStackPop(&s));
	// 断言报错
	//printf("出栈: 栈顶元素为: %d\n", LinkStackPop(&s));

	LinkStackDestroy(&s);

	return 0;
}
