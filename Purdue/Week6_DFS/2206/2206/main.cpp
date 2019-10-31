#include <stdio.h>
#pragma warning (disable : 4996)

const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };

bool map[1000][1000] = { false };
bool visited[1000][1000] = { false };

void dfs(int count, int x, int y, int N, int M, bool chance, int &min) {
	if (x == N -1 && y == M - 1) {
		if (min > count && count != -1) min = count;
		return;
	}
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx > -1 && nx < N && ny > -1 && ny < M) {
			if (visited[nx][ny]) continue;
			if (!map[nx][ny]) {
				visited[nx][ny] = true;
				dfs(count + 1, nx, ny, N, M, chance, min);
				visited[nx][ny] = false;
			}
			else if(chance) {
				visited[nx][ny] = true;
				dfs(count + 1, nx, ny, N, M, !chance, min);
				visited[nx][ny] = false;
			}
		}
	}
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++) {
		scanf("\n");
		for (int j = 0; j < M; j++) {
			char input;
			scanf("%c", &input);
			map[i][j] = input - 48;
		};
	}
	int answer = 1000 * 1000 + 1;
	dfs(1, 0, 0, N, M, true, answer);
	if (answer == 1000 * 1000 + 1) answer = -1;
	printf("%d", answer);
	return 0;
}