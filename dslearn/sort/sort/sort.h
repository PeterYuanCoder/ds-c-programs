#pragma once
#include<stdio.h>


//交换函数
void Swap(int* x, int* y);

//直接插入排序
void InsertSort(int* a, int n);

//希尔排序
void ShellSort(int* a, int n);

//简单选择排序
void SelectSort(int* a, int n);

//冒泡排序
void BubbleSort(int* a, int n);

//快排
void QuickSort(int* a, int left, int right);

//挖空法
int PartitionDigHole(int* a, int left, int right);

//计数排序
