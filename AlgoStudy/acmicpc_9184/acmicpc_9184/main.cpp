#include <stdio.h>

#pragma warning(disable:4996)

int main() {
	int matrix[15][15][15] = { 0, };
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				matrix[i][j][k] = 1;
	matrix[1][1][1] = 2;

	int a, b, c;
	for (int i = 0; i < 20; i++) {

	}
	return 0;
}
