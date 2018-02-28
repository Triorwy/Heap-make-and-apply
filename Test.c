#include"Heap.h"

void TestHeap()
{
	int i = 0;
	DataType a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
	MakeHeap(a, sizeof(a) / sizeof(DataType));
	DataType nArray[1000] = { 0 };
	srand((unsigned int )time(NULL));
	for (int i = 0; i < 1000; i++)
	{
		nArray[i] = rand() % 10000;
	}
	nArray[50] = 10001;
	nArray[350] = 10002;
	nArray[120] = 10007;
	nArray[4] = 10004;
	nArray[999] = 10006;
	TopK(nArray, 1000, 5);



}
void TestPriorityQueue()
{
	PryQueue q;
	PriorityQueueInit(&q);
	PriorityQueuePush(&q, 5);
	PriorityQueuePush(&q, 2);
	PriorityQueuePush(&q, 3);
	PriorityQueuePush(&q, 7);
	PriorityQueuePush(&q, 6);
	PriorityQueuePush(&q, 1);
	PriorityQueuePush(&q, 4);
	size_t size = PriorityQueueSize(&q);
	while (PriorityQueueEmpty(&q) != 0)
	{
		printf("%d ", PriorityQueueTop(&q));
		PriorityQueuePop(&q);
	}
	printf("\n");
	HeapSort(&q, size);
}

int main()
{
	/estHeap();
	TestPriorityQueue();
	system("pause");
	return 0;
}
