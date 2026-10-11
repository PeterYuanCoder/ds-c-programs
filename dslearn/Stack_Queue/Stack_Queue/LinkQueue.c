#define _CRT_SECURE_NO_WARNINGS

#include"LinkQueue.h"

// 初始化队列
void QueueInit(LinkQueue* q)
{
	assert(q);
	q->front = q->rear = (QNode*)malloc(sizeof(QNode));   //申请哨兵位，不存数据，这时候头指针和尾指针都是同一块区域
	if (q->front == NULL)
	{
		perror("QueueInit()::malloc()");
		return;
	}
	q->front->next = NULL;
	q->size = 0;
}

// 将x入队列
void EnQueue(LinkQueue* q, QDataType x)
{
	assert(q);
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL)
	{
		perror("EnQueue()::malloc()");
		return;
	}
	newNode->data = x;
	newNode->next = NULL;

	q->rear->next = newNode;
	q->rear = newNode;
	q->size++;
}


// 出队并返回队头数据
QDataType DeQueue(LinkQueue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	QNode* delNode = q->front->next;
	QDataType val = delNode->data;
	q->front->next = delNode->next;
	//如果除头结点之外只有一个结点
	if (q->rear == delNode)
	{
		q->rear = q->front;
	}
	free(delNode);
	delNode = NULL;
	q->size--;
	return val;
}


// 获取队头元素
QDataType QueueFront(LinkQueue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->front->next->data;
}


// 检测队列是否为空，空返回真，否则返回假
bool QueueEmpty(LinkQueue* q)
{
	assert(q);
	return q->size == 0;
}


// 获取队列中有效元素个数
int QueueSize(LinkQueue* q)
{
	assert(q);
	return q->size;
}



// 销毁队列
void QueueDestroy(LinkQueue* q)
{
	assert(q);
	QNode* cur = q->front;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->rear = q->front = NULL;
	q->size = 0;
}