#include <iostream>
#include <stdio.h>

#pragma warning (disable : 4996)

using namespace std;

#define MAX_X 40
#define MAX_Y 40

//int table[2][MAX_X][MAX_Y] = { 0, };

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
		int N, M, K;
		scanf("%d %d %d", &N, &M, &K);
		
		int table[2][MAX_X][MAX_Y] = { 0, };

		int init_x = (MAX_X - N) / 2;
		int init_y = (MAX_Y - M) / 2;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &table[0][init_x + i][init_y + j]);
			}
		}

		int size = 0;
		bool flag = false;
		for (int i = 0; i < K; i++) {
			for (int x = init_x - size; x < init_x + N + size; x++) {
				for (int y = init_y - size; y < init_y + M + size; y++) {
					if (table[0][x][y] != 0 && table[1][x][y] <= (table[0][x][y] * 2)) {
						table[1][x][y]++;
						if (table[1][x][y] == table[0][x][y] + 1) {
							if (table[0][x + 1][y] == 0 || table[1][x + 1][y] == 100) {
								if (table[0][x + 1][y] < table[0][x][y]) {
									table[0][x + 1][y] = table[0][x][y];
									table[1][x + 1][y] = 100;
								}
							}
							if (table[0][x][y + 1] == 0 || table[1][x][y + 1] == 100) {
									if (table[0][x][y + 1] < table[0][x][y]) {
										table[0][x][y + 1] = table[0][x][y];
										table[1][x][y + 1] = 100;
									}
								}
							if (table[0][x - 1][y] == 0 || table[1][x - 1][y] == 100) {
									if (table[0][x - 1][y] < table[0][x][y]) {
										table[0][x - 1][y] = table[0][x][y];
										table[1][x - 1][y] = 100;
									}
								}
							if (table[0][x][y - 1] == 0 || table[1][x][y - 1] == 100) {
									if (table[0][x][y - 1] < table[0][x][y]) {
										table[0][x][y - 1] = table[0][x][y];
										table[1][x][y - 1] = 100;
									}
								}
							flag = true;
						}
					}
				}
				
			}
			if (flag) {
				size++;
				flag = false;
			}
			for (int x = init_x - size; x < init_x + N + size; x++) {
				for (int y = init_y - size; y < init_y + M + size; y++) {
					if (table[1][x][y] == 100) table[1][x][y] = 0;
				}
			}
		}		

		int answer = 0;
		for (int x = init_x - size; x < init_x + N + size; x++) {
			for (int y = init_y - size; y < init_y + M + size; y++) {
				if (table[0][x][y] != 0) {
					if (table[1][x][y] < (table[0][x][y] * 2)) answer++;
					table[1][x][y] = 0;
					table[0][x][y] = 0;
				}
			}
		}
		printf("#%d %d\n", test_case, answer);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}