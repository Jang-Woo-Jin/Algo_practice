#include <stdio.h>

#pragma warning(disable : 4996)

#define MAX 12

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

void copyArray(int obj[2], int origin[2]) {
	obj[0] = origin[0];
	obj[1] = origin[1];
}

int slope(char board[MAX][MAX], int obj[2], int block[2], int end[2], int dir) {
	if (obj[0] == -1 && obj[1] == -1) return 0;
	while (board[obj[1]][obj[0]] != '#') {
		if (board[obj[1] + dy[dir]][obj[0] + dx[dir]] != '#' && !((obj[0] + dx[dir] )== block[0] && (obj[1] + dy[dir]) == block[1])) {
			obj[0] += dx[dir];
			obj[1] += dy[dir];

			if (obj[0] == end[0] && obj[1] == end[1]) {
				obj[0] = -1;
				obj[1] = -1;
				return -1;
			}
		}
		else break;
	}
	return 0;
}

int game(char board[MAX][MAX], int red[2], int blue[2], int end[2], int count) {
	if (count > 10) return -1;
	
	int ans[4];
	int tempR[2], tempB[2];
	int flagR1, flagB1, flagR2, flagB2;
	for (int i = 0; i < 4; i++) {
		//if (count == 1)
		//	printf("1");
		copyArray(tempR, red); copyArray(tempB, blue);
		flagR1 = slope(board, tempR, tempB, end, i); 
		flagB1 = slope(board, tempB, tempR, end, i);
		flagR2 = slope(board, tempR, tempB, end, i);
		flagB2 = slope(board, tempB, tempR, end, i);
		if ((flagR1 == -1 || flagR2 == -1 )&& (flagB1 == -1 || flagB2 == -1)) ans[i] = -1;
		else if (flagR1 == -1 || flagR2 == -1) ans[i] = count;
		else if (flagB1 == -1 || flagB2 == -1) ans[i] = -1;
		else ans[i] = game(board, tempR, tempB, end, count + 1);
	}
	int answer = 100;
	for (int i = 0; i < 4; i++) {
		if (answer > ans[i] && ans[i] != -1) answer = ans[i];
	}
	if (answer == 100) answer = -1;
	return answer;
}

int main() {
	
	int N, M;
	scanf("%d %d", &N, &M);

	char board[MAX][MAX];
	for (int i = 0; i < N; i++) scanf("%s", &board[i]);

	int red[2] = { 0, }, blue[2] = { 0, }, end[2] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 'R') {
				red[0] = j;
				red[1] = i;
			}
			else if (board[i][j] == 'B') {
				blue[0] = j;
				blue[1] = i;
			}
			else if (board[i][j] == 'O') {
				end[0] = j;
				end[1] = i;
			}
		}
	}

	int answer = game(board, red, blue, end, 1);

	printf("%d\n", answer);

	return 0;
}