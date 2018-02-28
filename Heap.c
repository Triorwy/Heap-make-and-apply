#include"Heap.h"

void AdjustDownBig(DataType* a, size_t n, int root)//向下调整
{
	size_t parent = root;
	size_t child = 2 * parent + 1;
	while (child < n)
	{
		if (a[child] < a[child + 1] && child + 1 < n)
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			DataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;

			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}

}
void MakeHeap(DataType* a, size_t n)//创建大堆
{
	int i = (n - 2) >> 1;
	for (; i >= 0; i--)
	{
		AdjustDownBig(a, n, i);
	}
}



void AdjustDownSmall(DataType* a, size_t n, int root)//向下调整
{
	size_t parent = root;
	size_t child = 2 * parent + 1;
	while (child < n)
	{
		if (a[child] > a[child + 1] && child + 1 < n)
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			DataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;

			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}

}

void TopK(DataType *a, size_t n, size_t k)//取n中最大的前k个
{
	int i = (k - 2) >> 1;
	size_t _k = k;
	for (; i >= 0; i--)
	{
		AdjustDownSmall(a, k, i);
	}
	for (i = k; i < n; i++)
	{
		if (a[i] > a[0])
		{
			a[0] = a[i];
			AdjustDownSmall(a, k, 0);
		}
	}

	for (i = 0; i < k; i++)
	{
		printf("%d ", a[i]);

	}
	printf("\n");
}
///////////////////////////////////////////////
void PriorityQueueInit(PryQueue* q)//初始化
{
	assert(q);
	q->_size = 0;
	for (int i = 0; i<1000; i++)
	{
		q->_a[i] = 0;
	}
}
void AdjustUp(DataType* a, size_t n, int child)//向上调整
{
	size_t parent = (child - 1) >> 1;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			DataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;

			child = parent;
			parent = (child - 1) >> 1;
		}
		else
		{
			break;
		}
	}
}
void PriorityQueuePush(PryQueue* q, DataType x)//插入
{
	if (q->_size == 0)
	{
		q->_a[q->_size] = x;
		q->_size++;
	}
	else
	{
		q->_a[q->_size] = x;
		q->_size++;
		AdjustUp(q->_a, q->_size, q->_size - 1);

	}
}
void PriorityQueuePop(PryQueue* q)//删除
{
	assert(q);
	q->_a[0] = q->_a[q->_size - 1];
	q->_size--;
	AdjustDownSmall(q->_a,q->_size,0);

}
DataType PriorityQueueTop(PryQueue* q)//取最大的
{
	assert(q);
	return q->_a[0];
}
size_t PriorityQueueSize(PryQueue* q)//返回个数
{
	assert(q);
	return q->_size;

}
size_t PriorityQueueEmpty(PryQueue* q)//对列是否为空
{
	assert(q);
	return q->_size == 0 ? 0 : q->_size;
}

void HeapSort(DataType* a, size_t n)//堆排序
{
	MakeHeap(a, n);//建大堆
	for (int i = n ; i > 0; i--)
	{
		printf("%d ", a[0]);
		a[0] = a[ i- 1];
		AdjustDownBig(a, i - 1, 0);
	}
	printf("\n");

}
