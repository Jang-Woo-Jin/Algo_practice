#include <stdio.h>
#include <string.h>
#include <vector>

#pragma warning(disable : 4996)

using namespace std;
#define MAX 22

const int dx[4] = { 1, -1, -1, 1 };
const int dy[4] = { 1, 1, -1, -1 };

void resetValue(int check[MAX][MAX], vector<int> checked[2]) {
	for (int i = 0; i < checked[0].size(); i++) {
		check[checked[1].at(i)][checked[0].at(i)] = 0;
	}
}

void checkMap(int map[MAX][MAX], int check[MAX][MAX], int x, int y, int N, vector<int> checked[2]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == 0 && map[i][j] == map[y][x]) {
				check[i][j] = 1;

				checked[0].push_back(j);
				checked[1].push_back(i);
			}
		}
	}
}

int checkLen(int map[MAX][MAX], int check[MAX][MAX], int x, int y, int N, int count) {
	vector<int> checked[2];
	int len = 0, cx = x, cy = y;
	while (1) {
		cx += dx[count];
		cy += dy[count];
		if (!(cy < N && cy > -1 && cx < N && cx > -1 && check[cy][cx] == 0)) {
			break;
		}
		checkMap(map, check, cx, cy, N, checked);
		len++;
	}
	resetValue(check, checked);
	return len;
}
int findWay(int map[MAX][MAX], int check[MAX][MAX], int x, int y, int dist[4], int N, int count) {
	
	vector<int> checked[2];
	for (int i = 1; i < dist[count - 1]; i++) {
		checkMap(map, check, x - dx[count - 1] * i, y - dy[count - 1] * i, N, checked);
	}
	checkMap(map, check, x, y, N, checked);
	
	int len = 0, cx = x, cy = y;
	
	len = checkLen(map, check, x, y, N, count);

	if (count == 2 && dist[0] != len) {
		resetValue(check, checked);
		return -1;
	}
	else if (count == 3) {
		if(dist[1] != len + 1) {
			resetValue(check, checked); 
			return -1;
		}
		else {
			int total_dist = 0;
			for (int i = 0; i < 3; i++) total_dist += dist[i];
			resetValue(check, checked);
			return total_dist + len + 1;
		}

	}

	int answer = -1;
	for (int i = len; i > 0; i--) {
		cx = x + dx[count] * i;
		cy = y + dy[count] * i;
		dist[count] = i;
		answer = findWay(map, check, cx, cy, dist, N, count + 1);
		if (answer > -1) break;
	}

	resetValue(check, checked);
	return answer;
}

int main() {
	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		int N;
		scanf("%d", &N);

		int map[MAX][MAX];
		memset(map, -1, sizeof(map));

		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &map[i][j]);

		int check[MAX][MAX] = { 0, };
		int dist[4];
		memset(dist, -1, sizeof(dist));

		int answer = -1, temp_ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				temp_ans = findWay(map, check, j, i, dist, N, 0);
				if (answer < temp_ans) answer = temp_ans;
			}
		}

		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}