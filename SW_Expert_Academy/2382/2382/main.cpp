#include <stdio.h>
#include <string.h>
#include <vector>

#pragma warning(disable : 4996)

using namespace std;
#define MAXC 102
#define MAXB 1000
#define DIE -5

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

void checkMulti(int bac[MAXB][4], vector<int> table[MAXC][MAXC], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (table[i][j].size() > 2) {
				int max_num = table[i][j].at(0);
				for (vector<int>::iterator iter = table[i][j].begin(); iter != table[i][j].end(); iter++) {
					if (bac[max_num][2] < bac[*iter][2]) max_num = *iter;
				}
				for (vector<int>::iterator iter = table[i][j].begin(); iter != table[i][j].end(); iter++) {
					if (*iter != max_num) {
						bac[max_num][2] += bac[*iter][2];
						bac[*iter][2] = 0;
					}
				}
			}
			if (table[i][j].size() == 2) {
				int b1 = table[i][j].at(0);
				int b2 = table[i][j].at(1);

				if (bac[b1][2] > bac[b2][2]) {
					bac[b1][2] += bac[b2][2];
					bac[b2][2] = 0;
				}
				else {
					bac[b2][2] += bac[b1][2];
					bac[b1][2] = 0;
				}
			}
		}
	}
}

int main() {
	int test_case = 0;
	scanf("%d", &test_case);

	for (int t = 1; t <= test_case; t++) {
		int N, M, K;
		scanf("%d %d %d", &N, &M, &K);

		int bac[MAXB][4];
		memset(bac, -1, sizeof(bac));
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < 4; j++) {
				scanf("%d", &bac[i][j]);
				if (j == 3) bac[i][j]--;
			}
		}
		
		int map[MAXC][MAXC];
		memset(map, -1, sizeof(map));
		for (int i = 0; i < N; i++) {
			map[0][i] = DIE;
			map[N - 1][i] = DIE;
			map[i][0] = DIE;
			map[i][N - 1] = DIE;
		}

		//for (int i = 0; i < K; i++) {
		//	map[bac[i][0]][bac[i][1]] = -1;
		//}

		int answer = 0;
		vector<int> table[MAXC][MAXC];

		for (int m = 0; m < M; m++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					table[i][j].clear();
				}
			}
			for (int i = 0; i < K; i++) {
				if (bac[i][2] > 0) {
					bac[i][0] = bac[i][0] + dy[bac[i][3]];
					bac[i][1] = bac[i][1] + dx[bac[i][3]];
					table[bac[i][0]][bac[i][1]].push_back(i);

					if (map[bac[i][0]][bac[i][1]] == DIE) {
						bac[i][2] /= 2;
						if (bac[i][3] == 0) bac[i][3] = 1;
						else if (bac[i][3] == 1) bac[i][3] = 0;
						else if (bac[i][3] == 2) bac[i][3] = 3;
						else if (bac[i][3] == 3) bac[i][3] = 2;
					}
				}
			}
			checkMulti(bac, table, N);
		}
		for (int i = 0; i < K; i++) {
			answer += bac[i][2];
		}
		printf("#%d %d\n", t, answer);
	}
	return 0;
}