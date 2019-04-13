#include <stdio.h>
#include <string.h>

#pragma warning (disable : 4996)

#define MAX 22

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

bool isInTable(int x, int y, int N) {
	return (x > -1 && y > -1 && x < N && y < N);
}

void copyTable(int temp[MAX][MAX], int map[MAX][MAX], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = map[i][j];
		}
	}
}

int findMaxNum(int map[MAX][MAX], int N) {
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			answer = answer > map[i][j] ? answer : map[i][j];
		}
	}
	return answer;
}

void moveMap(int map[MAX][MAX], int d, int st_ed[2][3], int N) {
	int temp[MAX][MAX];
	memset(temp, -1, sizeof(temp));
	copyTable(temp, map, N);

	int cx = 0, cy = 0;
	for (int i = st_ed[d % 2][0]; i != st_ed[d % 2][1]; i += st_ed[d % 2][2]) {
		for (int j = st_ed[d % 2][0]; j != st_ed[d % 2][1]; j += st_ed[d % 2][2]) {
			cx = j, cy = i;
			while (1) {
				cx += dx[d]; cy += dy[d];
				if (isInTable(cx, cy, N) && map[cy][cx] == 0) continue;
				else {
					cx -= dx[d]; cy -= dy[d];
					break;
				}
			}
			if (!(cy == i && cx == j)) {
				map[cy][cx] = map[i][j];
				map[i][j] = 0;
			}
		}
	}
}

void addMap(int map[MAX][MAX], int d, int st_ed[2][3], int N) {
	int temp[MAX][MAX];
	memset(temp, -1, sizeof(temp));
	copyTable(temp, map, N);

	int cx = 0, cy = 0;
	for (int i = st_ed[d % 2][0]; i != st_ed[d % 2][1]; i += st_ed[d % 2][2]) {
		for (int j = st_ed[d % 2][0]; j != st_ed[d % 2][1]; j += st_ed[d % 2][2]) {
			if (map[i][j] != 0) {
				cx = j + dx[d], cy = i + dy[d];
				if (isInTable(cx, cy, N) && map[cy][cx] == map[i][j]) {
					map[cy][cx] += map[i][j];
					map[i][j] = 0;
				}
			}
		}
	}
}

int playGame(int map[MAX][MAX], int d, int count, int st_ed[2][3], int N) {
	if (count == 5) return findMaxNum(map, N);

	moveMap(map, d, st_ed, N);
	addMap(map, d, st_ed, N);
	moveMap(map, d, st_ed, N);

	int temp[MAX][MAX];
	memset(temp, -1, sizeof(temp));
	
	int max_ans = 0, ans = 0;
	for (int i = 0; i < 4; i++) {
		copyTable(temp, map, N);
		ans = playGame(temp, i, count + 1, st_ed, N);
		max_ans = max_ans > ans ? max_ans : ans;
	}
	return max_ans;
}

int main() {
	int N;
	scanf("%d", &N);

	int st_ed[2][3] = { {0, N, 1}, {N - 1, -1, -1} };

	int map[MAX][MAX];
	memset(map, -1, sizeof(map));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int temp[MAX][MAX];
	memset(temp, -1, sizeof(temp));
	
	int max_ans = 0, ans = 0;
	for (int i = 0; i < 4; i++) {
		copyTable(temp, map, N);
		ans = playGame(temp, i, 0, st_ed, N);
		max_ans = max_ans > ans ? max_ans : ans;
	}

	printf("%d", max_ans);
	return 0;
}