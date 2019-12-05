#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };

void search(int map[100][100], int x, int y, int size, int num) {
	map[x][y] = 2;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx > -1 && nx < size && ny > -1 && ny < size) {
			if (map[nx][ny] == 1) search(map, nx, ny, size, num);
		}
	}
}

int main() {
	int size;
	scanf("%d\n", &size);

	int map[100][100];
	memset(map, -1, sizeof(int) * 100 * 100);

	int max = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			scanf("%d", &map[i][j]);
			max = max > map[i][j] ? max : map[i][j];
		}
	}

	
	int test[100][100];
	memset(test, -1, sizeof(int) * 100 * 100);

	int testMax = 1;
	for (int n = max - 1; n > 0; n--) {
		int num = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				test[i][j] = map[i][j] - n > 0 ? 1 : 0;
			}
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (test[i][j] == 1) {
					search(test, i, j, size, num++);
					testMax = testMax > num ? testMax : num;
				}
			}
		}
	}

	printf("%d\n", testMax);
	return 0;
}