#include <stdio.h>
#include <string.h>
#include <algorithm>
#pragma warning(disable : 4996)

const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };

void search(int map[25][25], int x, int y, int size, int num, int list[25]) {
	map[x][y] = 2;
	list[num]++;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx > -1 && nx < size && ny > -1 && ny < size) {
			if (map[nx][ny] == 1) search(map, nx, ny, size, num, list);
		}
	}
}
	
int main() {
	int size;
	scanf("%d\n", &size);
	
	int map[25][25];
	memset(map, -1, sizeof(int) * 25 * 25);

	for (int i = 0; i < size; i++) {
		char num[25];
		scanf("%s", &num);
		for (int j = 0; j < size; j++) {
			map[i][j] = num[j] - '0';
		}
	}

	int num = 0;
	int list[323] = {0, };
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (map[i][j] == 1) search(map, i, j, size, num++, list);
		}
	}

	std::sort(list, list + num);
	printf("%d\n", num);
	for (int i = 0; i < num; i++) {
		printf("%d\n", list[i]);
	}
	return 0;
}