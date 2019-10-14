#include <stdio.h>
#include <string.h>
#include <algorithm>

#pragma warning(disable : 4996)

bool movable(int list[15], int col) {
	for (int i = 0; i < col; i++) {
		if (list[i] == list[col] || abs(list[i] - list[col]) == abs(i - col)) {
			return false;
		}
	}
	return true;
}

void nqueen(int col, int size, int list[15], int &answer) {
	if (size == col) {
		answer++;
		return;
	}
	for (int i = 0; i < size; i++) {
		list[col] = i;
		if (movable(list, col)) {
			nqueen(col + 1, size, list, answer);
		}
	}
}

int main() {
	int size;
	scanf("%d", &size);

	int answer = 0;
	int list[15];
	memset(list, -1, sizeof(int) * 15);
	nqueen(0, size, list, answer);
	printf("%d", answer);
	return 0;
}
