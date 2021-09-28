#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct student {
	char num[15];
	char name[20];
	int score;
	//추가 가능
}student;
int main() {
	int cnt = 0;
	char line[100];
	char* p_line;
	p_line = line;
	//int i = 0;
	char* token = " ,";
	int select = 0;
	student* stds = (student*)malloc(100*sizeof(student));
	while (1) {
		printf("학생의 정보를 입력하시오. (학번, 이름, 점수 순으로 한 줄에 입력, 종료하려면 'stop')\n");
		for (int i = 0;; i++) {
			*(p_line + i) = getchar();
			if (*(p_line + i) == '\n') {
				*(p_line + i) = NULL;
				break;
			}
		}
		if (strcmp(line, "stop") == 0) {
			break;
		}
		strcpy((stds + cnt)->num , strtok(line, token));
		strcpy((stds + cnt)->name, strtok(NULL, token));
		(stds + cnt)->score = atoi(strtok(NULL, token));
		cnt++;
		
	}
	while (select != 4) {
		printf("무엇을 표기할까요? (1: 학번, 2: 이름, 3: 점수, 4: 종료)\n");
		scanf("%d", &select);
		switch (select) {
		case 1:
			for (int i = 0; i < cnt; i++) {
				printf("No%d. %s\n", i + 1, (stds + i)->num);
			}
			break;
		case 2:
			for (int i = 0; i < cnt; i++) {
				printf("No%d. %s\n", i + 1, (stds + i)->name);
			}
			break;
		case 3:
			for (int i = 0; i < cnt; i++) {
				printf("No%d. %d\n", i + 1, (stds + i)->score);
			}
			break;
		}
	}
	free(stds);

	return 0;
}
