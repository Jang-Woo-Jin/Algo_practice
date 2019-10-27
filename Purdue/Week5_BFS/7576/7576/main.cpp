#include <stdio.h>
#include <queue>
#include <algorithm>
#pragma warning (disable : 4996)

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int map[1000][1000] = { 0, };

int main() {
	int M, N;
	scanf("%d %d", &M, &N);

	int need = 0;
	std::queue<std::pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) need++;
			else if (map[i][j] == 1) q.push(std::pair<int, int>(i, j));
		}
	}
	
	int day = 0, num = 0;
	while (need > 0) {
		if (num == 0 || q.empty()) {
			num = q.size();
			if (num == 0) {
				printf("-1");
				return 0;
			}
			day++;
		}
		std::pair<int, int> loc = q.front();
		q.pop();
		num--;
		int y = loc.first, x = loc.second;
		for (int i = 0; i < 4; i++) {
			if (x + dx[i] > -1 && x + dx[i] < M && y + dy[i] > -1 && y + dy[i] < N) {
				if (map[y + dy[i]][x + dx[i]] == 0) {
					map[y + dy[i]][x + dx[i]] = 1;
					need--;
					q.push(std::pair<int, int>(y + dy[i], x + dx[i]));
				}
			}
		}
	}
	printf("%d", day);
	return 0;
}