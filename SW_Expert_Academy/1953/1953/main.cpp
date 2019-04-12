#include <stdio.h>
#include <string.h>

#pragma warning (disable : 4996)

#define MAX 50
#define HIT 10

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

const int turnel[8][4] = {	{0, 0, 0, 0},
							{1, 1, 1, 1},
							{1, 1, 0, 0},
							{0, 0, 1, 1},
							{1, 0, 0, 1},
							{0, 1, 0, 1},
							{0, 1, 1, 0},
							{1, 0, 1, 0}	};

bool isInMap(int x, int y, int N, int M) {
	return (x > -1 && y > -1 && x < M && y < N);
}

int countMap(int checked[MAX][MAX], int N, int M) {
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (checked[i][j] > -1) answer++;
		}
	}
	return answer;
}

bool isConnect(int i, int kind) {
	bool flag = false;
	if (i == 0 && turnel[kind][1]) flag = true;
	else if (i == 1 && turnel[kind][0]) flag = true;
	else if (i == 2 && turnel[kind][3]) flag = true;
	else if (i == 3 && turnel[kind][2]) flag = true;
	
	return flag;
}

void copyTable(int copying[MAX][MAX], int copied[MAX][MAX], int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copying[i][j] = copied[i][j];
		}
	}
}

void search(int map[MAX][MAX], int checked[MAX][MAX], int x, int y, int time, int N, int M, int L) {
	checked[y][x] = time;

	if (time == L) return;

	int temp[MAX][MAX];
	memset(temp, -1, sizeof(temp));
	copyTable(temp, checked, N, M);

	int kind = map[y][x];
	int cx = x, cy = y;
	int answer = 0;
	for (int i = 0; i < 4; i++) {
		if (turnel[kind][i]) {
			cx = x + dx[i]; 
			cy = y + dy[i];
			if (isInMap(cx, cy, N, M) && (checked[cy][cx] == -1 || checked[cy][cx] > time)) {
				int tkind = map[cy][cx];
				if (isConnect(i, tkind)) {
					copyTable(temp, checked, N, M);
					search(map, checked, cx, cy, time + 1, N, M, L);
				}
			}
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		int N, M, X, Y, L;
		scanf("%d %d %d %d %d", &N, &M, &Y, &X, &L);
		
		int map[MAX][MAX];
		memset(map, -1, sizeof(map));
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		int checked[MAX][MAX];
		memset(checked, -1, sizeof(checked));

		search(map, checked, X, Y, 1, N, M, L);

		int answer = countMap(checked, N, M);
		
		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}