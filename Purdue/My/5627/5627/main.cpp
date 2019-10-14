#include <stdio.h>

#pragma warning (disable : 4996)

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

const int dir_x[4] = { 0, 1, 0, -1 };
const int dir_y[4] = { -1, 0, 1, 0 };

typedef struct {
	int map[50][50] = { 0, };
	int dir = -1;
	int position_x = -1;
	int position_y = -1;
}Bacteria;

int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	int trap[2];
	scanf("%d %d", &trap[0], &trap[1]);

	Bacteria bac[5];
	for (int i = 0; i < K; i++) {
		int x, y;
		char dir;
		scanf("%d %d %c", &x, &y, &dir);

		bac[i].position_x = x;
		bac[i].position_y = y;
		if (dir == 'U') bac[i].dir = UP;
		else if (dir == 'R') bac[i].dir = RIGHT;
		else if (dir == 'D') bac[i].dir = DOWN;
		else if (dir == 'L') bac[i].dir = LEFT;

		for (int n = 0; n < N; n++) {
			int row;
			scanf("%d", &row);
			for (int m = 0; m < M; m++) {
				bac[i].map[n][M - m - 1] = row % 10;
				row /= 10;
			}
		}
	}
	return 0;
}