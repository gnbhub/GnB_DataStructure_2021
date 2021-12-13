#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int cal(int num1, int num2, char op);
int main() {
	int num1, num2;
	char op;
	//int(*cal1)(int num1, int num2, char op);
	printf("정수 (a b): ");
	scanf("%d %d", &num1, &num2);
	getchar();
	printf("연산자: ");
	scanf("%c", &op);
	int(*cal1)(int num1, int num2, char op);
	cal1 = cal;
	printf("Ans: %p\n", cal1(num1, num2, op));
	return 0;
}
int cal(int num1, int num2, char op) {
	int op_int = op - '0';
	switch (op_int) {
	case '+' - '0':
		return num1 + num2;
		break;
	case '-' - '0':
		return num1 - num2;
		break;
	case '*' - '0':
		return num1 * num2;
		break;
	case '/' - '0':
		return num1 / num2;
		break;
	case '%' - '0':
		return num1 % num2;
		break;
	default:
		printf("ERROR\n");
		return 0;
	}


}
