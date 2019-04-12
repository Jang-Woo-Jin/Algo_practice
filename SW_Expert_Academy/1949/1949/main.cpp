#include <stdio.h>
#include <string.h>

#pragma warning (disable : 4996)

#define MAX 10

int main() {
	int T;
	scanf("%d", &T);
	
	for (int test_case = 1; test_case <= T; test_case++) {
		int N, K;
		scanf("%d %d", &N, &K);

		int map[MAX][MAX];
		memset(map, -1, sizeof(map));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}



		int answer = 0;
		printf("#%d %d", test_case, answer);
	}
	return 0;
}