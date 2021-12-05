#include <time.h>
#include "queues.h"

void fillQueues(QUEUE*);
void printQueues(QUEUE*);

void printOneQueue(QUEUE* pQueue, int []);
void printMostFrequentNumber(int []);

int main(void)
{
	QUEUE* lotto;

	printf("로또 번호 생성기\n");

	lotto = createQueue();

	fillQueues(lotto);
	printQueues(lotto);

	return 0;
}

void fillQueues(QUEUE* lotto)
{
	int item;
	int* dataPtr;

	printf("generated lotto number:\n");
	srand(time(NULL));

	for (int i = 1; i <= 1000; i++) {
		if (!(dataPtr = (int*)malloc(sizeof(int))))
			printf("Overflow in fillQueues\a\n"),
			exit(100);
		
		*dataPtr = item = rand() % 45 + 1;
		printf("%3d", item);
		if (!(i % 10))
			printf("\n");

		enqueue(lotto, dataPtr);
	}
	printf("End of generated lotto number\n\n");
	return;
}

void printQueues(QUEUE* lotto)
{
	int array[45] = { 0 };
	printOneQueue(lotto, array);
	printMostFrequentNumber(array);

	return;
}

void printOneQueue(QUEUE* pQueue, int array[])
{
	int* dataPtr;
	while (!emptyQueue(pQueue))
	{
		dequeue(pQueue, (void*)&dataPtr);
		array[*dataPtr - 1 ]++;
	}

	return;
}

void printMostFrequentNumber(int array[])
{
	int max_index = 0;
	for (int i = 0; i < 45; i++)
	{
		printf("%3d : %d번|", i + 1,array[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	
	printf("\n제일 많이 나온 로또 번호 : ");
	for (int j = 0; j < 6; j++)
	{
		int max = array[0]; //max의 값 array의 첫 번째 원소로 초기화
		for (int i = 0; i < 45; i++)
		{
			if (array[i] >= max)
			{
				max = array[i];
				max_index = i;
			}
		}
		array[max_index] = 0;
		printf("%d ", max_index + 1);
	}
	
	return;
}
