#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef TreeNode* Element2;

typedef struct tQueueNode {
    Element2 data;
    struct tQueueNode* next;
}QueueNode;

typedef struct Queue {
    int count;
    QueueNode* front, * rear;
}Queue;

Queue* CreateQueue();
void Enqueue(Queue* p_Queue, Element2 item);
Element2 Dequeue(Queue* p_Queue);
bool IsEmptyQueue(Queue* p_Queue);

Queue* CreateQueue() {
    Queue* p_Queue = (Queue*)malloc(sizeof(Queue));
    if (p_Queue == NULL)
        return NULL;
    p_Queue->count = 0;
    p_Queue->front = p_Queue->rear = NULL;
    return p_Queue;
}

void Enqueue(Queue* p_Queue, Element2 item) {
    QueueNode* p_QueueNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (p_QueueNode == NULL)
        return;
    p_QueueNode->data = item;
    p_QueueNode->next = NULL;
    if (p_Queue->count == 0) {
        p_Queue->front = p_Queue->rear = p_QueueNode;
    }
    else {
        p_Queue->rear->next = p_QueueNode;
        p_Queue->rear = p_QueueNode;
    }
    p_Queue->count++;
}

Element2 Dequeue(Queue* p_Queue) {
    Element2 item = NULL;
    QueueNode* p_Front = NULL;
    if (IsEmptyQueue(p_Queue)) {
        printf("The Queue is Empty!\n");
        return NULL;
    }
    else {
        p_Front = p_Queue->front;
        item = p_Front->data;
        if (p_Queue->count == 1) {
            p_Queue->front = p_Queue->rear = NULL;
        }
        else {
            p_Queue->front = p_Front->next;
            free(p_Front);
        }
    }
    p_Queue->count--;
    return item;
}

bool IsEmptyQueue(Queue* p_Queue) {
    return (p_Queue->count == 0);
}

void DestroyQueue(Queue* p_Queue) {
    QueueNode* Q1, * Q2;
    for (Q1 = NULL, Q2 = p_Queue->front; Q2 != NULL; Q1 = Q2) {
        Q2 = Q2->next;
        free(Q1);
    }
    free(p_Queue);
}
