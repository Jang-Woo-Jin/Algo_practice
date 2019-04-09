#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#pragma warning (disable : 4996)
using namespace std;

#define MAXM 100
#define MAXA 8
#define MAXMAP 10

void settingMap(int map[MAXA][MAXMAP][MAXMAP], int battery[MAXA][4], int num) {
	int x = battery[num][0];
	int y = battery[num][1];
	int p = battery[num][2];

	map[num][y][x] = num;
	for (int i = 1; i <= p; i++) {
		if (y + i < MAXMAP) map[num][y + i][x] = num;
		if (x + i < MAXMAP)	map[num][y][x + i] = num;
		if (y - i > -1) map[num][y - i][x] = num;
		if (x - i > -1) map[num][y][x - i] = num;
	}
	for (int sy = 1; sy < p; sy++) {
		for (int sx = 1; sx <= p - sy; sx++) {
			if (y + sy < MAXMAP && x + sx < MAXMAP) map[num][y + sy][x + sx] = num;
			if (y + sy < MAXMAP && x - sx > -1) map[num][y + sy][x - sx] = num;
			if (y - sy > -1 && x + sx < MAXMAP) map[num][y - sy][x + sx] = num;
			if (y - sy > -1 && x - sx > - 1) map[num][y - sy][x - sx] = num;
		}
	}
	
}

void move(int h[2], int dir) {
	if (dir == 1) h[1]--;
	else if (dir == 2) h[0]++;
	else if (dir == 3) h[1]++;
	else if (dir == 4) h[0]--;
}

void findLargest(int max[2], vector<int> list, int battery[MAXA][4]) {
	for (vector<int>::iterator iter = list.begin(); iter != list.end(); iter++) {
		if (battery[max[0]][3] < battery[*iter][3]) {
			max[1] = max[0];
			max[0] = *iter;
		}
		else if (*iter != max[0] && battery[max[1]][3] < battery[*iter][3]){
			max[1] = *iter;
		}
	}
}

int checkTable(vector<int> h1, vector<int> h2, int battery[MAXA][4]) {
	int answer = 0;
	int len1 = h1.size(), len2 = h2.size();
	
	if (len1 > 1 && len2 > 1) {
		int max1[2] = { h1.at(0), h1.at(1) }, max2[2] = { h2.at(0), h2.at(1) };
		findLargest(max1, h1, battery);
		findLargest(max2, h2, battery);

		if (max1[0] == max2[0]) {
			if (battery[max1[1]][3] > battery[max2[1]][3]) {
				answer += battery[max1[1]][3];
				answer += battery[max2[0]][3];
			}
			else {
				answer += battery[max1[0]][3];
				answer += battery[max2[1]][3];
			}
		}
		else {
			answer += battery[max1[0]][3];
			answer += battery[max2[0]][3];
		}
	}
	else if (len1 > 1 && len2 == 1) {
		answer += battery[h2.at(0)][3];

		int max[2] = { h1.at(0), h1.at(1) };
		findLargest(max, h1, battery);

		if (max[0] == h2.at(0)) answer += battery[max[1]][3];
		else answer += battery[max[0]][3];
	}
	else if (len1 == 1 && len2 > 1) {
		answer += battery[h1.at(0)][3];
		
		int max[2] = { h2.at(0), h2.at(1) };
		findLargest(max, h2, battery);

		if (max[0] == h1.at(0)) answer += battery[max[1]][3];
		else answer += battery[max[0]][3];
	}
	else if (len1 == 1 && len2 == 1) {
		if (h1.at(0) == h2.at(0)) answer += battery[h1.at(0)][3];
		else {
			answer += battery[h1.at(0)][3];
			answer += battery[h2.at(0)][3];
		}
	}
	else if (len1 > 0 && len2 == 0) {
		if (len1 > 1) {
			int max[2] = { h1.at(0), h1.at(1) };
			findLargest(max, h1, battery);
			answer += battery[max[0]][3];
		}
		else {
			answer += battery[h1.at(0)][3];
		}
	}
	else if (len1 == 0 && len2 > 0) {
		if (len2 > 1) {
			int max[2] = { h2.at(0), h2.at(1) };
			findLargest(max, h2, battery);
			answer += battery[max[0]][3];
		}
		else {
			answer += battery[h2.at(0)][3];
		}
	}
	return answer;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int M, A;
		scanf("%d %d", &M, &A);

		int h[2][MAXM];
		int battery[MAXA][4];
		int map[MAXA][MAXMAP][MAXMAP];
		
		memset(h, -1, sizeof(h));
		memset(battery, -1, sizeof(battery));
		memset(map, -1, sizeof(map));
		
		int h0[2] = { 0, 0 };
		int h1[2] = { 9, 9 };

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &h[i][j]);
			}
		}
		for (int i = 0; i < A; i++) {
			for (int j = 0; j < 4; j++) {
				scanf("%d", &battery[i][j]);
				if (j == 0 || j == 1) battery[i][j]--;
			}
			settingMap(map, battery, i);
		}
		
		int answer = 0;
		for (int i = 0; i <= M; i++) {
			vector<int> h0_b;
			vector<int> h1_b;
			for (int j = 0; j < A; j++) {
				if (map[j][h0[1]][h0[0]] != -1) h0_b.push_back(map[j][h0[1]][h0[0]]);
				if (map[j][h1[1]][h1[0]] != -1) h1_b.push_back(map[j][h1[1]][h1[0]]);
			}
			answer += checkTable(h0_b, h1_b, battery);

			printf("h0 - x : %d, y : %d ==", h0[0], h0[1]);
			for (vector<int>::iterator i = h0_b.begin(); i != h0_b.end(); i++) {
				printf(" %d", *i);
			}
			printf("\nh1 - x : %d, y : %d ==", h1[0], h1[1]);
			for (vector<int>::iterator i = h1_b.begin(); i != h1_b.end(); i++) {
				printf(" %d", *i);
			}

			printf("    : %d\n", answer);
			printf("==============\n");
			move(h0, h[0][i]);
			move(h1, h[1][i]);
		}
		printf("#%d %d\n", test_case, answer);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}