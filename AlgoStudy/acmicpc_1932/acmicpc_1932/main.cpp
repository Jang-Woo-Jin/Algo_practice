#include <stdio.h>

#pragma warning(disable : 4996)

int main() {
	int size;
	scanf("%d", &size);

	int tri[500][500] = { 0, };

	for (int i = 0; i < size; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &tri[i][j]);
		}
	}


	for (int i = size - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (tri[i][j] > tri[i][j + 1]) tri[i - 1][j] += tri[i][j];
			else tri[i - 1][j] += tri[i][j + 1];
		}
	}
	printf("%d", tri[0][0]);
	return 0;
}
