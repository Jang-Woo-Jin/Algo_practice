#include <stdio.h>
#include <string.h>

#pragma warning (disable : 4996)

#define MAX 22

int calPay(int k) {
	int ans = 1;
	for (int i = 1; i <= k; i++) {
		ans += (4 * (i - 1));
	}
	return ans;
}

void copyTable(int temp[MAX][MAX], int map[MAX][MAX], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = map[i][j];
		}
	}
}

int checkMap(int map[MAX][MAX], int k, int x, int y, int N) {
	int answer = 0;
	for (int i = 0; i < k; i++) {
		for (int j = k - i - 1; j >= 0; j--) {
			if (y + j < N && x + i < N)	if (map[y + j][x + i] == 1) { map[y + j][x + i] = 2; answer++; }
			if (y + j < N && x - i > -1) if (map[y + j][x - i] == 1) { map[y + j][x - i] = 2; answer++; }
			if (y - j > -1 && x + i < N) if (map[y - j][x + i] == 1) { map[y - j][x + i] = 2;  answer++; }
			if (y - j > -1 && x - i > -1) if (map[y - j][x - i] == 1) { map[y - j][x - i] = 2; answer++; }
		}
	}
	return answer;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		int N, M;
		scanf("%d %d", &N, &M);
		
		int map[MAX][MAX];
		memset(map, -1, sizeof(map));

		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &map[i][j]);

		int answer = 1, tempAnswer = 0, pay = 0;
		int temp[MAX][MAX];
		memset(temp, -1, sizeof(temp));
		for (int c = 2; c < (N / 2 + 1); c++) {
			for (int i = c / 2 - 1; i < N - (c / 2 - 1) ; i++) {
				pay = calPay(c);
				for (int j = c / 2 - 1; j < N - (c / 2 - 1); j++) {
					copyTable(temp, map, N);
					tempAnswer = checkMap(temp, c, i, j, N);
					if (tempAnswer * M >= pay) {
						if (tempAnswer > answer) answer = tempAnswer;
					}
				}
			}
		}
		//int answer = 0;
		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}