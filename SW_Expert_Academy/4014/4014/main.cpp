#include <iostream>
#include <stdio.h>

#pragma warning (disable : 4996)

using namespace std;

#define MAX 20

bool checkRoad(int map[MAX], int N, int X) {
	int h = map[0];
	int ucount = 0;
	for (int i = 0; i < N; i++) {
		if (map[i] == h) {
			ucount++;
		}
		else if (map[i] > h + 1 || map[i] < h - 1) return false;
		else if (map[i] == h + 1) {
			if (ucount >= X) {
				h++;;
				ucount = 1;
			}
			else {
				return false;
			}
		}
		else if (map[i] == h - 1) {
			if (i + X > N) return false;
			for (int j = 0; j < X; j++) {
				if (map[i + j] != h - 1) return false;
			}
			h--;
			i += X - 1;
			ucount = 0;
		}
	}
	return true;
}

int main(int argc, char** arg)
{
	/*
	int N = 12, X = 2;
	int map[MAX] = { 0, };
	for (int i = 0; i < N; i++) {
		scanf("%d", &map[i]);
	}
	bool f = checkRoad(map, N, X);
	printf("%d", f);
	*/
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int map[MAX][MAX] = { 0, };

		int N, X;
		scanf("%d %d", &N, &X);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		int answer = 0;
		for (int i = 0; i < N; i++) {
			if (checkRoad(map[i], N, X)) answer++;
			}
		int trans[MAX][MAX] = { 0, };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				trans[i][j] = map[j][i];
			}
		}
		for (int i = 0; i < N; i++) {
			if (checkRoad(trans[i], N, X)) answer++;
		}
		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}