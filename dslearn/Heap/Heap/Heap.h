#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef int HeapDataType;
typedef struct {
	HeapDataType* a;
	int size;      //元素个数
	int capacity;   //堆的容量
}Heap;


typedef int BTDataType;
// 二叉链
typedef struct BinaryTreeNode {
	struct BinaryTreeNode* left;   // 指向左孩子的指针
	struct BinaryTreeNode* right;  // 指向右孩子的指针
	BTDataType data;               // 数据元素
}BTNode;


//交换函数
void Swap(int* x, int* y);

//向上调整算法
void AdjustUp(HeapDataType* a, int child);

//向下调整算法
void AdjustDown(HeapDataType* a, int n, int parent);

//默认初始化堆
void HeapInit(Heap* hp);

//利用给定数组初始化建堆
void HeapInitArray(Heap* hp, HeapDataType* a, int n);

//堆的销毁
void HeapDestroy(Heap* hp);

//堆的插入
void HeapPush(Heap* hp, HeapDataType x);

// 堆的删除，删除堆顶数据
void HeapPop(Heap* hp);

// 获取堆顶数据
HeapDataType HeapTop(Heap* hp);

// 判空
int HeapEmpty(Heap* hp);

//获取堆的数据个数
int HeapSize(Heap* hp);

//前序遍历
void Preorder(BTNode* root);

//中序遍历
void Inorder(BTNode* root);

//后序遍历
void Postorder(BTNode* root);
