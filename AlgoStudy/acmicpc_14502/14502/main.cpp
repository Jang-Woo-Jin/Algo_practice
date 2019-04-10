#include <stdio.h>
#include <string.h>

#pragma warning (disable : 4996)

#define MAX 11

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };
void spreadVirus(int map[MAX][MAX], int x, int y, int N, int M) {
	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i], cy = y + dy[i];
		if (cy > -1 && cy < N && cx > -1 && cx < M) {
			if (map[cy][cx] == 0) {
				map[cy][cx] = 2;
				spreadVirus(map, cx, cy, N, M);
			}
		}
	}
}

int countVirus(int map[MAX][MAX], int virus[MAX][2], int vcount, int N, int M) {
	for (int i = 0; i < vcount; i++) {
		spreadVirus(map, virus[i][0], virus[i][1], N, M);
	}
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) answer += 1;
		}
	}
	return answer;
}

void copyArray(int temp[MAX][MAX], int map[MAX][MAX], int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[i][j] = map[i][j];
		}
	}
}

int BF(int map[MAX][MAX], int check[MAX][MAX], int virus[MAX][2], int vcount, int N, int M, int count) {
	if (count > 3) {
		return countVirus(map, virus, vcount, N, M);
	}
	int temp[MAX][MAX], tempCheck[MAX][MAX];
	memset(temp, -1, sizeof(temp));
	memset(tempCheck, -1, sizeof(tempCheck));

	int answer = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 && check[i][j] == -1) {
				copyArray(temp, map, N, M);
				copyArray(tempCheck, check, N, M);
				temp[i][j] = 1; 
				tempCheck[i][j] = 1;
				int tempAns = BF(temp, tempCheck, virus, vcount, N, M, count + 1);
				if (answer < tempAns) answer = tempAns;
			}
		}
	}
	return answer;
}

int main() {
	int M, N;
	scanf("%d %d", &N, &M);
	int map[MAX][MAX];
	int virus[MAX][2];
	int vcount = 0;
	memset(map, -1, sizeof(map)); memset(virus, -1, sizeof(virus));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				virus[vcount][0] = j;
				virus[vcount++][1] = i;
			}
		}
	}
	
	int check[MAX][MAX];
	memset(check, -1, sizeof(check));
	int answer = BF(map, check, virus, vcount, N, M, 1);
	
	printf("%d\n", answer);
	return 0;
}