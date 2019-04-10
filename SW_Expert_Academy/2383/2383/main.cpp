#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>

#pragma warning (disable : 4996)

using namespace std;

#define MAX 10

void sortDistance(int sort[MAX], int s, int hcount, int distance[MAX][2]) {
	int tempd[MAX] = { 0, };
	for (int i = 0; i < hcount; i++) {
		tempd[i] = distance[sort[i]][s];
	}

	int temp;
	for (int i = 0; i < hcount; i++) {
		for (int j = 0; j < hcount; j++) {
			if (tempd[i] < tempd[j]) {
				temp = sort[i];
				sort[i] = sort[j];
				sort[j] = temp;

				temp = tempd[i];
				tempd[i] = tempd[j];
				tempd[j] = temp;
			}
		}
	}
}

int calculateStair(int sort[MAX], int size, int s, int stair[2][3], int distance[MAX][2]) {
	int ans[3] = { 0, };
	int t = 0;
	for (int i = 0; i < (1 + size / 3); i++) {
		t = 0 + 3 * i;
		if (t < size) {
			if (i == 0) ans[0] = distance[sort[t]][s] + stair[s][2];
			else {
				if (ans[0] > distance[sort[t]][s]) ans[0] += stair[s][2];
				else ans[0] = distance[sort[t]][s] + stair[s][2];
			}
		}
		if (t + 1 < size) {
			if (i == 0) ans[1] = distance[sort[t + 1]][s] + stair[s][2];
			else {
				if (ans[1] > distance[sort[t + 1]][s]) ans[1] += stair[s][2];
				else ans[1] = distance[sort[t + 1]][s] + stair[s][2];
			}
		}
		if (t + 2 < size) {
			if (i == 0) ans[2] += distance[sort[t + 2]][s] + stair[s][2];
			else {
				if (ans[2] > distance[sort[t + 2]][s]) ans[2] += stair[s][2];
				else ans[2] = distance[sort[t + 2]][s] + stair[s][2];
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < 3; i++) {
		if (answer < ans[i]) answer = ans[i];
	}
	return answer + 1;
}

int calculateTime(vector<int> s0, vector<int> s1, int stair[2][3], int distance[MAX][2]) {
	int sort0[MAX], sort1[MAX];
	memset(sort0, -1, sizeof(sort0)); memset(sort1, -1, sizeof(sort1));

	int cs0 = s0.size(), cs1 = s1.size();
	for (int i = 0; i < cs0; i++) sort0[i] = s0.at(i);
	for (int i = 0; i < cs1; i++) sort1[i] = s1.at(i);

	sortDistance(sort0, 0, cs0, distance);
	sortDistance(sort1, 1, cs1, distance);
	
	int ans[2] = { 0, };
	ans[0] = calculateStair(sort0, cs0, 0, stair, distance);
	ans[1] = calculateStair(sort1, cs1, 1, stair, distance);

	int answer = 0;
	if (ans[0] > ans[1]) answer = ans[0];
	else answer = ans[1];

	return answer;
}

int goStair(int h, int hcount, vector<int> s0, vector<int> s1, int stair[2][3], int distance[MAX][2]){
	if (h < hcount) {
		vector<int> temp0 = s0, temp1 = s1;
		temp0.push_back(h); temp1.push_back(h);

		int a1 = goStair(h + 1, hcount, temp0, s1, stair, distance);
		int a2 = goStair(h + 1, hcount, s0, temp1, stair, distance);

		return a1 < a2 ? a1 : a2;
	}
	else {
		return calculateTime(s0, s1, stair, distance);
	}
}

int main(int argc, char** arg)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int map[MAX][MAX];
		int human[MAX][2];
		int distance[MAX][2];
		int stair[2][3];
		int hcount = 0;
		int scount = 0;
		memset(map, 0, sizeof(map)); memset(stair, -1, sizeof(stair)); memset(human, -1, sizeof(human));

		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &map[i][j]);
		
		//set human and stair
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1) {
					human[hcount][0] = j;
					human[hcount++][1] = i;
				}
				else if (map[i][j] > 1) {
					stair[scount][0] = j;
					stair[scount][1] = i;
					stair[scount++][2] = map[i][j];
				}
			}
		}
		
		//calculate distance
		for (int h = 0; h < hcount; h++) {
			for (int s = 0; s < 2; s++) {
				distance[h][s] = abs(human[h][0] - stair[s][0]) + abs(human[h][1] - stair[s][1]);
			}
		}

		vector<int> s0, s1;
		//int answer = goStair(0, hcount, s0, s1, stair, distance);
		//for (int i = 1; i < 2; i++) s0.push_back(i);
		s0.push_back(2); s0.push_back(5);
		s1.push_back(0); s1.push_back(1);  s1.push_back(3); s1.push_back(4);
		for (int i = 6; i < hcount; i++) s1.push_back(i);

		int answer = calculateTime(s0, s1, stair, distance);
		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}