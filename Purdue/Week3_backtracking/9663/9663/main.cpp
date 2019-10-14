#include <stdio.h>

#pragma warning(disable : 4996)

const int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

void nqueen(int chess[15][15], int x, int count, int size, int &answer, int remain);
void copyMatrix(int origin[15][15], int copy[15][15], int size);
int attackWay(int chess[15][15], int x, int y, int size);
bool checkInBox(int x, int y, int size);

int main() {
	int size;
	scanf("%d", &size);

	int chess[15][15] = { 0, };
	
	int answer = 0;
	nqueen(chess, 0, 0, size, answer, size * size);
	printf("%d", answer);
	return 0;
}

void nqueen(int chess[15][15], int x, int count, int size, int &answer, int remain) {
	if (count == size) {
		answer++;
		return;
	}
	if (remain + count < size) return;
	for (int i = x; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (chess[i][j] == 0) {
				int copy[15][15] = { 0, };
				copyMatrix(chess, copy, size);
				int remainN = remain - attackWay(copy, i, j, size);
				nqueen(copy, i + 1, count + 1, size, answer, remainN);
			}
		}
	}
}

void copyMatrix(int origin[15][15], int copy[15][15], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			copy[i][j] = origin[i][j];
		}
	}
}

int attackWay(int chess[15][15], int x, int y, int size) {
	int count = 1;
	chess[x][y] = 2;
	for (int i = 1; i <= size; i++) {
		for (int j = 0; j < 8; j++) {
			if (checkInBox(x + dx[j] * i, y + dy[j]* i, size) && chess[x + dx[j] * i][y + dy[j] * i] == 0) {
				chess[x + dx[j] * i][y + dy[j] * i] = 1;
				count++;
			}
		}
	}
	return count;
}

bool checkInBox(int x, int y, int size) {
	if (x >= 0 && y >= 0 && x < size && y < size) return true;
	else return false;
}