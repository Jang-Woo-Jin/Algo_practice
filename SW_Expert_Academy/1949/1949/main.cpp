#include <stdio.h>
#include <string.h>
#include <vector>

#pragma warning (disable : 4996)

using namespace std;

#define MAX 10
#define HIT 100

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

void copyTable(int temp[MAX][MAX], int origin[MAX][MAX], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = origin[i][j];
		}
	}
}

bool isInTable(int x, int y, int N) {
	return (x > -1 && y > -1 && x < N && y < N);
}

int search(int map[MAX][MAX], int checked[MAX][MAX], int x, int y, int count, bool cut_flag, int N, int K) {
	checked[y][x] = HIT;
	
	int temp[MAX][MAX];
	memset(temp, -1, sizeof(temp));

	int max_ans = 0, ans = 0;
	int cx = 0, cy = 0;
	for (int i = 0; i < 4; i++) {
		cx = x + dx[i]; cy = y + dy[i];
		if (isInTable(cx, cy, N) && checked[cy][cx] != HIT) {
			if (map[cy][cx] < map[y][x]) {
				copyTable(temp, checked, N);
				ans = search(map, temp, cx, cy, count + 1, cut_flag, N, K);
				max_ans = max_ans > ans ? max_ans : ans;
			}
			else if (map[cy][cx] - K < map[y][x] && cut_flag) {
				int cmap[MAX][MAX];
				memset(cmap, -1, sizeof(cmap));

				copyTable(cmap, map, N);
				cmap[cy][cx] = map[y][x] - 1;

				copyTable(temp, checked, N);
				ans = search(cmap, temp, cx, cy, count + 1, false, N, K);
				max_ans = max_ans > ans ? max_ans : ans;
			}
		}
	}
	if (max_ans == 0) return count;
	else return max_ans;
}

int main() {
	int T;
	scanf("%d", &T);
	
	for (int test_case = 1; test_case <= T; test_case++) {
		int N, K;
		scanf("%d %d", &N, &K);

		int map[MAX][MAX];
		memset(map, -1, sizeof(map));

		int max_h = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				max_h = max_h > map[i][j] ? max_h : map[i][j];
			}
		}

		int max_list[5][2];
		memset(max_list, -1, sizeof(max_list));
		
		int max_count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == max_h) {
					max_list[max_count][0] = j;
					max_list[max_count++][1] = i;
				}
			}
		}

		int checked[MAX][MAX], temp[MAX][MAX];
		memset(checked, -1, sizeof(checked));
		memset(temp, -1, sizeof(temp));
		int max_ans = 0, ans = 0;
		for (int i = 0; i < max_count; i++) {
			copyTable(temp, checked, N);
			ans = search(map, temp, max_list[i][0], max_list[i][1], 1, true, N, K);
			max_ans = max_ans > ans ? max_ans : ans;
		}

		printf("#%d %d", test_case, max_ans);
	}
	return 0;
}