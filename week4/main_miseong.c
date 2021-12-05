#define _CRT_SECURE_NO_WARNINGS
#include "stacksADT.h"

int priority(char token);
bool isOperator(char token);
int calc(int operand1, int oper, int operand2);
char* infixToPostfix(); //중위표기법 -> 후위표기법 변환 함수
int evaluatePostfix(char* postfix); //후위표기법 계산 함수

int main(void)
{
	char *postfix = infixToPostfix();

	//후위 표기법 출력
	printf("The postfix formula is: ");
	puts(postfix);

	int result = evaluatePostfix(postfix);
	printf("The result is : %d\n", result);
}

int priority(char token)
{
	if (token == '*' || token == '/')
		return 2;
	if (token == '+' || token == '-')
		return 1;
	return 0;
} //priority

bool isOperator(char token)
{
	if (token == '*' || token == '/' || token == '+' || token == '-')
		return true;
	return false;
} //isOperator

int calc(int operand1, int oper, int operand2)
{
	int result = 0;

	switch (oper)
	{
	case'+': result = operand1 + operand2;
		break;
	case '-': result = operand1 - operand2;
		break;
	case '*': result = operand1 * operand2;
		break;
	case '/': result = operand1 / operand2;
		break;
	} // switch

	return result;
}//calc



//중위 표기법 -> 후위 표기법 변환 함수
char* infixToPostfix()
{
	static char postfix[80] = { 0 };
	char temp[2] = { 0 };
	char token;
	char* dataPtr;
	STACK* stack;

	stack = createStack();

	printf("Enter an infix formula: ");

	while ((token = getchar()) != '\n')
	{
		if (token == '(')
		{
			dataPtr = (char*)malloc(sizeof(char));
			*dataPtr = token;
			pushStack(stack, dataPtr);
		} // if
		else if (token == ')')
		{
			dataPtr = (char*)popStack(stack);
			while (*dataPtr != '(')
			{
				temp[0] = *dataPtr;
				strcat(postfix, temp);
				dataPtr = (char*)stackTop(stack);
			} //while
		}//else if
		else if (isOperator(token))
		{
			dataPtr = (char*)stackTop(stack);
			while (!emptyStack(stack) && priority(token) <= priority(*dataPtr))
			{
				dataPtr = (char*)popStack(stack);
				temp[0] = *dataPtr;
				strcat(postfix, temp);
				dataPtr = (char*)stackTop(stack);
			} //while
			dataPtr = (char*)malloc(sizeof(char));
			*dataPtr = token;
			pushStack(stack, dataPtr);
		}//else if
		else // 문자 = 피연산자!
		{
			temp[0] = token;
			strcat(postfix, temp);
		} //else
	} //while get token

	//infix formula empty. Pop stack to postfix
	while (!emptyStack(stack))
	{
		dataPtr = (char*)popStack(stack);
		temp[0] = *dataPtr;
		strcat(postfix, temp);
	} // while

	destroyStack(stack);

	return postfix;
}

//후위 표기법 계산 함수
int evaluatePostfix(char* postfix) {
	char token;
	int operand1;
	int operand2;
	int value;

	int* dataPtr;
	STACK* stack;

	stack = createStack();

	int i = 0;
	while ((token = *(postfix++)) != '\0')
	{
		if (!isOperator(token))
		{
			dataPtr = (int*)malloc(sizeof(int));
			*dataPtr = atoi(&token);
			pushStack(stack, dataPtr);
		} //if
		else
		{
			dataPtr = (int*)popStack(stack);
			operand2 = *dataPtr;
			dataPtr = (int*)popStack(stack);
			operand1 = *dataPtr;
			value = calc(operand1, token, operand2);
			dataPtr = (int*)malloc(sizeof(int));
			*dataPtr = value;
			pushStack(stack, dataPtr);
		}//else
	}//while

	dataPtr = (int*)popStack(stack);
	value = *dataPtr;

	destroyStack(stack);
	return value;
}
