#define _CRT_SECURE_NO_WARNINGS
#include "header.h"

int main() {
	int choice;
	int input;
	Stack *binaryArray = CreateStack();

	while (1) {
		printf("1. add /2. delete /3. remove");
		scanf("%d", &choice);
		if (choice == 1) {
			printf("input binary number : ");
			scanf("%d", &input);
			if (isBinary(input))
				Push(binaryArray, input);
			else
			{
				printf("invalid value");
				continue;
			}
		}
		else if (choice == 2) {
			Pop(binaryArray);

		}
		else if (choice == 3) {
			DestroyStack(binaryArray);
		}
		else {
			printf("Retry");
			continue;
		}
	}
	return 0;
}
