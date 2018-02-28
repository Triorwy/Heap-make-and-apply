# Heap-make-and-apply
Heap make and apply
#pragma once

#include<stdio.h>

#include<windows.h>

#include<time.h>

#include<assert.h>

#define N 1000
typedef int DataType;

typedef struct PriorityQueue
{
	DataType _a[N];
	size_t _size;
	//DataType* _a; //动态的
	//size_t _size; 
	//size_t _capacity;
}PryQueue;

void AdjustDownBig(DataType* a, size_t n, int root);//向下调整
void AdjustDownSmall(DataType* a, size_t n, int root);//向下调整
void MakeHeap(DataType* a, size_t n);//创建堆
void AdjustUp(DataType* a, size_t n, int root);//向上调整
void TopK(DataType *a, size_t n, size_t k);//取n中最大的前k个

/////////////////////////////////////////////////////
//优先级队列

void PriorityQueueInit(PryQueue* q);//初始化
void PriorityQueuePush(PryQueue* q,DataType x);//插入
void PriorityQueuePop(PryQueue* q);//删除
DataType PriorityQueueTop(PryQueue* q);//取最大的
size_t PriorityQueueSize(PryQueue* q);//返回个数
size_t PriorityQueueEmpty(PryQueue* q);//对列是否为空

void HeapSort(DataType* a, size_t n);//堆排序



