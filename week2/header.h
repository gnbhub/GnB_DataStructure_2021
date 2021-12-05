#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int* Element;
typedef struct tStackNode {
	Element data;
	struct tStackNode* next;
}StackNode;

typedef struct {
	int count;
	StackNode* top;
}Stack;

Stack* CreateStack();
void Push(Stack* p_stack, Element item);
Element Pop(Stack* p_stack);
Element Top(Stack* p_stack);
void DestroyStack(Stack* p_stack);
bool IsEmptyStack(Stack* p_stack);
int CountStackItem(Stack* p_stack);
void ClearStack(Stack* p_stack);
void ShowAllStack(Stack* p_stack);
bool isBinary(int input);

bool IsBinary(int input) {
	if (input == 0 || input == 1) return true;
	else return false;
}

Stack* CreateStack() {
	Stack* p_Stack = (Stack*)malloc(sizeof(Stack));
	if (p_Stack == NULL)
		return NULL;
	p_Stack->count = 0;
	p_Stack->top = NULL;
	return p_Stack;
}

void Push(Stack* p_stack, Element item) {
	StackNode* p_NewNode = (StackNode*)malloc(sizeof(StackNode));
	if (p_NewNode == NULL)
		return;
	p_NewNode->data = item;
	p_NewNode->next = p_stack->top;
	p_stack->top = p_NewNode;
	p_stack->count++;
}

Element Pop(Stack* p_stack) {
	int top_element;
	StackNode* p_StackNode;
	if (IsEmptyStack(p_stack)) {
		printf("Stack is empty\n");
		return;
	}
	else {
		top_element = p_stack->top->data;
		p_stack->top->data = NULL;
		p_StackNode = p_stack->top;
		p_stack->top = p_StackNode->next;
		free(p_StackNode);
		p_stack->count--;
		return top_element;
	}
}
Element Top(Stack* p_stack) {
	Element top_element;
	if (IsEmptyStack(p_stack)) {
		printf("Stack is empty\n");
		return;
	}
	else {
		top_element = p_stack->top->data;
		return top_element;
	}
}
void DestroyStack(Stack* p_stack) {
	StackNode* p_StackNode = NULL, * p_NextNode = NULL;
	if (p_stack->count > 0) {
		p_NextNode = p_stack->top;
		while (p_NextNode) {
			p_StackNode = p_NextNode;
			p_NextNode = p_StackNode->next;
			free(p_StackNode);
		}
	}
	free(p_stack);
}
bool IsEmptyStack(Stack* p_stack) {
	if (p_stack->count == 0)
		return true;
	else return false;
}
int CountStackItem(Stack* p_stack) {
	return p_stack->count;
}
void ClearStack(Stack* p_stack) {
	while (!IsEmptyStack(p_stack)) {
		Pop(p_stack);
	}
}
