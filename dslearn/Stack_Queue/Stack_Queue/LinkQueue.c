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
	q->front = NULL;
	q->size = 0;
}

// 将x入队列
void EnQueue(LinkQueue* q, QDataType x)
{
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
	QNode* delNode = q->front->next;
	QDataType val = delNode->data;
	q->front->next = delNode->next;
	//如果除头结点之外只有一个结点
	if (q->rear == delNode)
	{
		q->rear = q->front;
	}
	free(delNode);
	q->size--;
	return val;
}