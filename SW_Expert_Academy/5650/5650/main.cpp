#include <iostream>
#include <stdio.h>
#include <string.h>

#pragma warning (disable : 4996)
using namespace std;

#define MAX_S 102
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int hitFigure(int direction, int figure) {
	switch (figure) {
	case 1:
		if (direction == UP) return DOWN;
		else if (direction == DOWN) return RIGHT;
		else if (direction == LEFT) return UP;
		else if (direction == RIGHT) return LEFT;
	case 2:
		if (direction == UP) return RIGHT;
		else if (direction == DOWN) return UP;
		else if (direction == LEFT) return DOWN;
		else if (direction == RIGHT) return LEFT;
	case 3:
		if (direction == UP) return LEFT;
		else if (direction == DOWN) return UP;
		else if (direction == LEFT) return RIGHT;
		else if (direction == RIGHT) return DOWN;
	case 4:
		if (direction == UP) return DOWN;
		else if (direction == DOWN) return LEFT;
		else if (direction == LEFT) return RIGHT;
		else if (direction == RIGHT) return UP;
	case 5:
		if (direction == UP) return DOWN;
		else if (direction == DOWN) return UP;
		else if (direction == LEFT) return RIGHT;
		else if (direction == RIGHT) return LEFT;
	case 6: case 7: case 8: case 9: case 10:
		return direction;
	}
}

int move(int board[MAX_S][MAX_S], int table[MAX_S][MAX_S][4], int x, int y, int init_x, int init_y, int N, int direction) {
	int count = 0;
	int tx = x, ty = y;
	do {
		switch (direction) {
		case UP:
			ty--;
			break;
		case DOWN:
			ty++;
			break;
		case LEFT:
			tx--;
			break;
		case RIGHT:
			tx++;
			break;
		}
		if (((tx == init_x )&& (ty == init_y ))|| (board[ty][tx] == -1)) {
			return count;
		}
	} while (board[ty][tx] == 0);

	if (table[ty][tx][direction] == 0) {
		count++;
		if (board[ty][tx] > 5) {
			count--;
			int flag = false;
			for (int i = 1; i < N + 1; i++) {
				for (int j = 1; j < N + 1; j++) {
					if ((board[i][j] == board[ty][tx])& i != ty) {
						tx = j;
						ty = i;
						flag = true;
						break;
					}
				}
				if (flag) break;
			}
		}
		direction = hitFigure(direction, board[ty][tx]);
		count += move(board, table, tx, ty, init_x, init_y, N, direction);
		table[ty][tx][direction] = count;
	}
	return table[ty][tx][direction];
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		scanf("%d", &N);

		int board[MAX_S][MAX_S] = { 0, };
		int table[MAX_S][MAX_S][4] = { 0, };

		for (int i = 0; i < N + 2; i++) {
			board[0][i] = 5;
			board[N + 1][i] = 5;
			board[i][0] = 5;
			board[i][N + 1] = 5;
		}

		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				scanf("%d", &board[i][j]);
			}
		}

		int answer = 0;
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				if (board[i][j] == 0) {
					for (int d = 0; d < 4; d++) {
						table[i][j][d] = move(board, table, j, i, j, i, N, d);
						if (table[i][j][d] > answer) answer = table[i][j][d];
					}
					memset(table, 0, sizeof(table));
				}
			}
		}
		
		printf("#%d %d\n", test_case, answer);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}