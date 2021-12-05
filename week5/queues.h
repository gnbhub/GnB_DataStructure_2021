#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	void* dataPtr;
	struct node* next;
} QUEUE_NODE;

typedef struct
{
	QUEUE_NODE* front;
	QUEUE_NODE* rear;
	int count;
} QUEUE;

QUEUE* createQueue(void);
QUEUE* destroyQueue(QUEUE* queue);

bool dequeue(QUEUE* queue, void** itemPtr);
bool enqueue(QUEUE* queue, void* itemPtr);
bool queueFront(QUEUE* queue, void** itemPtr);
bool queueRear(QUEUE* queue, void** itemPtr);
int queueCount(QUEUE* queue);

bool emptyQueue(QUEUE* queue);
bool fullQueue(QUEUE* queue);

QUEUE* createQueue(void)
{
	QUEUE* queue;

	queue = (QUEUE*)malloc(sizeof(QUEUE));
	if (queue)
	{
		queue->front = NULL;
		queue->rear = NULL;
		queue->count = 0;
	}
	return queue;
}

bool enqueue(QUEUE* queue, void* itemPtr)
{
	QUEUE_NODE* newPtr;

	if (!(newPtr = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE))))
		return false;

	newPtr->dataPtr = itemPtr;
	newPtr->next = NULL;

	if (queue->count == 0)
		queue->front = newPtr;
	else
		queue->rear->next = newPtr;

	(queue->count)++;
	queue->rear = newPtr;
	return true;
}

bool dequeue(QUEUE* queue, void** itemPtr)
{
	QUEUE_NODE* deleteLoc;

	if (!queue->count)
		return false;

	*itemPtr = queue->front->dataPtr;
	deleteLoc = queue->front;
	if (!queue->count == 1)
		queue->rear = queue->front = NULL;
	else
		queue->front = queue->front->next;
	(queue->count)--;
	free(deleteLoc);

	return true;
}

bool queueFront(QUEUE* queue, void** itemPtr)
{
	if (!queue->count)
		return false;
	else
	{
		*itemPtr = queue->front->dataPtr;
		return true;
	}
}

bool queueRear(QUEUE* queue, void** itemPtr)
{
	if (!queue->count)
		return true;
	else
	{
		*itemPtr = queue->rear->dataPtr;
		return false;
	}
}

bool emptyQueue(QUEUE* queue) //공백 상태 검출 함수
{
	return (queue->count == 0);
}

bool fullQueue(QUEUE* queue) //포화 상태 검출 함수
{
	QUEUE_NODE* temp;

	temp = (QUEUE_NODE*)malloc(sizeof(*(queue->rear)));
	if (temp)
	{
		free(temp);
		return true;
	}
	return false;
}

QUEUE* destroyQueue(QUEUE* queue)
{
	QUEUE_NODE* deletePtr;

	if (queue)
	{
		while (queue->front != NULL)
		{
			free(queue->front->dataPtr);
			deletePtr = queue->front;
			queue->front = queue->front->next;
			free(deletePtr);
		}
		free(queue);
	}
	return NULL; // null pointer 반환
}
