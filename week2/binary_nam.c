#define _CRT_SECURE_NO_WARNINGS
#include "Stack_Link.h"
#include <stdio.h>
#include <stdbool.h>
int main() {
	int number;
	int n;
	Stack* st = CreateStack();
	printf("Enter a number: "); 
	scanf("%d", &number);
	printf("The binary number of %d: ", number);
	while (number >=1) {
		Push(st, number % 2);
		number /= 2;
	}
	while (!IsEmptyStack(st))
		printf("%d", Pop(st));
	printf("\n");
	DestroyStack(st);
	return 0;
}
