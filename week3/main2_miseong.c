#include <stdio.h>

int main() {

	printf("[char]\n");
	printf("%ubyte\npointer :%ubyte\n", sizeof(char), sizeof(char*));
	printf("[short]\n");
	printf("%ubyte\npointer :%ubyte\n", sizeof(short), sizeof(short*));
	printf("[int]\n");
	printf("%ubyte\npointer :%ubyte\n", sizeof(int), sizeof(int*));
	printf("[float]\n");
	printf("%ubyte\npointer :%ubyte\n", sizeof(float),sizeof(float*));
	printf("[double]\n");
	printf("%ubyte\npointer :%ubyte\n", sizeof(double), sizeof(double*));

	return 0;
}
