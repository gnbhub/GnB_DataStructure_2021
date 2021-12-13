#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int num1, num2;
	char op;
	int result;
}calculator;
int cal_result(int num1, int num2, char op);
int main() {
	FILE* pre_fp, * fp;
	calculator* cal;
	int line_cnt = 0;
	char line[50];
	char pre_line[50];
	char fname[20];
	int i = 0;
	while (1) {
		printf("File name: ");
		scanf("%s", fname);
		pre_fp = fopen(fname, "r");
		if (pre_fp == NULL) {
			printf("The file does not exist. \n");
			continue;
		}
		else {
			while (fgets(pre_line, 100, pre_fp) != NULL) {
				line_cnt++;
			}
			fclose(pre_fp);
			cal = (calculator*)malloc(line_cnt * sizeof(calculator));
			fp = fopen(fname, "r");
			while (fgets(line, 100, fp) != NULL) {
				(cal + i)->num1 = line[0] - '0';
				(cal + i)->op = line[1];
				(cal + i)->num2 = line[2] - '0';
				//printf("cal+%d: num1: %d, num2: %d, op: %c\n", i, (cal + i)->num1, (cal + i)->num2, (cal + i)->op);
				(cal + i)->result = cal_result((cal + i)->num1, (cal + i)->num2, (cal + i)->op);
				i++;
			}
			fclose(fp);
			printf("Result\n");
			for (i = 0; i < line_cnt; i++) {
				printf("%d. %d %c %d = %d\n", i + 1, (cal + i)->num1, (cal + i)->op, (cal + i)->num2, (cal + i)->result);
			}


			break;
		}
	}


	return 0;
}
int cal_result(int num1, int num2, char op) {
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
