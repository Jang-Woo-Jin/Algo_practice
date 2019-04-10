#include <stdio.h>
#include <string.h>

#pragma warning (disable : 4996)

#define MAX 22

int calPay(int k) {
	int ans = 1;
	for (int i = 1; i <= k; i++) {
		ans += (4 * (i - 1));
	}
}

void markMap(int map[MAX][MAX], int k, int x, int y, int N) {
	for (int i = 0; i < k; i++) {
		for (int j = k - i; j > 0; j--) {
			map[y + j][x + i] = 1;
		}
	}
}
int main() {
	int T;
	scanf("%d", &T);
	for (int test_case = 0; test_case < T; test_case++) {
		int N, M;
		scanf("%d %d", &N, &M);
		
		int map[MAX][MAX];
		memset(map, -1, sizeof(map));

		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &map[i][j]);


		int answer = 0;
		printf("#%d %d", test_case, answer);
	}
	return 0;
}