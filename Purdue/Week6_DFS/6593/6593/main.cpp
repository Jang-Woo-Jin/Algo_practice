#include <stdio.h>
#pragma warning (disable : 4996)


int main() {
	int L, R, C;
	scanf("%d %d %d", &L, &R, &C);
	while (!(L == 0 && R == 0 && C == 0)) {
		scanf("\n");
		char map[30][30][30] = {0, };	
		char useless;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int m = 0; m < C; m++) {
					scanf("%c", &map[i][j][m]);
				}
				scanf("\n");
			}
			scanf("\n"); 
		}



		scanf("%d %d %d", &L, &R, &C);
	}
	return 0;
}