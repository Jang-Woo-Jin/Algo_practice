#include <stdio.h>

#pragma warning(disable : 4996)

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

bool isMovable(char map[20][20], int x, int y, int R, int C) {
	if (x >= 0 && x < R && y >= 0 && y < C) {
		if (map[x][y] != -1) return true;
	}
	return false;
}

void findWay(char map[20][20], bool list[26], int x, int y, int count, int &maxNum, int R, int C) {
	count++;
	list[map[x][y] - 'A'] = false;
	for (int i = 0; i < 4; i++) {
		if (isMovable(map, x + dx[i], y + dy[i], R, C) && list[map[x + dx[i]][y + dy[i]] - 'A']) {
			findWay(map, list, x + dx[i], y + dy[i], count, maxNum, R, C);
		}
	}
	list[map[x][y] - 'A'] = true;
	if (count > maxNum) maxNum = count;
}


int main() {
	int R, C;
	scanf("%d %d", &R, &C);

	char map[20][20] = { 0, };
	for (int i = 0; i < R; i++) {
		scanf("%s", &map[i]);
	}

	bool list[26];
	for (int i = 0; i < 26; i++) list[i] = true;
	int maxNum = 0;
	findWay(map, list, 0, 0, 0, maxNum, R, C);
	printf("%d", maxNum);
	return 0;
}