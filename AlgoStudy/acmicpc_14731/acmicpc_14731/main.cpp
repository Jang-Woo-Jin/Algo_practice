#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable : 4996)
int** function_assign(int **function, int size);
void function_free(int **function, int size);

int twos[100000000]{ 0, };
int main() {
	int test = 2;
	int div = 1000000007;
	for (int i = 1; i < 40; i++) {
		test %= div;
		printf("%d\n", test);
		test *= 2;
	}

	int x;
	scanf("%d", &x);

	int **function = 0;
	function = function_assign(function, x);

	for (int i = 0; i < x; i++) {
		scanf("%d %d", &function[i][0], &function[i][1]);
	}

	for (int i = 0; i < x; i++) {
		function[i][0] *= function[i][1];
		function[i][1]--;
	}

	int answer = 0;
	for (int i = 0; i < x; i++) {
		if (function[i][1] >= 0) {
			for (int j = 0; j < function[i][1]; j++) {
				function[i][0] *= 2;
			}
			answer += function[i][0];
		}
	}
	printf("%d", answer);
	function_free(function, x);
	
	return 0;
}
int** function_assign(int **function, int size) {
	function = (int**)malloc(sizeof(int*) * size);
	for (int i = 0; i < size; i++) {
		function[i] = (int*)malloc(sizeof(int) * 2);
	}
	return function;
}

void function_free(int **function, int size) {
	for (int i = 0; i < size; i++) {
		free(function[i]);
	}
	free(function);
}