#include <stdio.h>

#pragma warning (disable : 4996)
int main() {
	int T;
	scanf("%d", &T);
	for (int c = 0; c < T; c++) {
		int N, P;
		scanf("%d %d", &N, &P);
		
		int map[10000][2] = { 0, };
		for (int i = 0; i < P; i++) {
			scanf("%d %d", &map[i][0], &map[i][1]);
		}
		printf("%d\n", N - 1);
	}
	return 0;
}