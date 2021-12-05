#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void pascaltriangle(int(*p)[10], int size);
void triangleprint(int(*p)[10], int size);

int main() {
	int pascal[10][10];

	int size = 0;
	printf("원하는 파스칼 삼각형의 크기를 입력하세요.\n");
	scanf("%d", &size);

	printf("\n\n");

	pascaltriangle(&pascal, size);
	triangleprint(&pascal, size);


	return 0;
}

//Size 크기의 파스칼 삼각형을 이차원 배열 p에 생성하는 함수
void pascaltriangle(int(*p)[10], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j == 0 || i == j)
			{
				p[i][j] = 1;
			}
			else
			{
				p[i][j] = p[i - 1][j] + p[i - 1][j - 1];
			}
		}
	}
}

//Size 크기 배열 p를 그림과 같이 삼각형만 출력하는 함수
void triangleprint(int(*p)[10], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i < j) {
				printf("\n");
				break;
			}
			else
				printf("%d ", p[i][j]);
		}
	}

}
