#include <stdio.h>
#include <string.h>

#pragma warning (disable : 4996)

#define MAX 10
#define CTV 5
const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

int seeTvOther(int map[MAX][MAX], int tv[CTV][MAX][2], int tv_count[CTV], int tvn, int count, int N, int M);

void copyTable(int copying[MAX][MAX], int copied[MAX][MAX], int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copying[i][j] = copied[i][j];
		}
	}
}

void seeMapOneDirection(int map[MAX][MAX], int x, int y, int d, int N, int M) {
	while (1) {
		x += dx[d]; 
		y += dy[d];
		if (x > -1 && y > -1 && x < M && y < N && map[y][x] != 6) {
			if(map[y][x] == 0) map[y][x] = 10;
		}
		else break;
	}
}

void seeTv5(int map[MAX][MAX], int tv[MAX][2], int tv_count, int N, int M) {
	int x, y;
	for (int i = 0; i < tv_count; i++) {
		x = tv[i][0]; y = tv[i][1];
		for (int j = 0; j < 4; j++) {
			seeMapOneDirection(map, x, y, j, N, M);
		}
	}
}

int countSave(int map[MAX][MAX], int N, int M) {
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) answer++;
		}
	}
	return answer;
}

int seeTv23(int map[MAX][MAX], int tv[CTV][MAX][2], int tv_count[CTV], int tvn, int x, int y, int d1, int d2, int count, int N, int M) {
	int temp[MAX][MAX];
	copyTable(temp, map, N, M);
	seeMapOneDirection(temp, x, y, d1, N, M);
	seeMapOneDirection(temp, x, y, d2, N, M);
	
	return seeTvOther(temp, tv, tv_count, tvn, count + 1, N, M);
}

int seeTvOther(int map[MAX][MAX], int tv[CTV][MAX][2], int tv_count[CTV], int tvn, int count, int N, int M) {
	int temp[MAX][MAX];
	memset(temp, -1, sizeof(temp));

	int answer = 1000, t_ans = 0;
	int x = tv[tvn][count][0], y = tv[tvn][count][1];

	if (tvn == 3) {
		if (count < tv_count[tvn]) {
			for (int j = 0; j < 4; j++) {
				copyTable(temp, map, N, M);
				for (int d = 0; d < 4; d++) {
					if (d != j) seeMapOneDirection(temp, x, y, d, N, M);
				}
				t_ans = seeTvOther(temp, tv, tv_count, tvn, count + 1, N, M);
				if (t_ans < answer) answer = t_ans;
			}
		}
		else {
			copyTable(temp, map, N, M);
			t_ans = seeTvOther(temp, tv, tv_count, tvn - 1, 0, N, M);
			if (t_ans < answer) answer = t_ans;
		}
		return answer;
	}
	else if (tvn == 2) {
		if (count < tv_count[tvn]) {
			t_ans = seeTv23(map, tv, tv_count, tvn, x, y, 0, 3, count, N, M);
			if (t_ans < answer) answer = t_ans;
			
			t_ans = seeTv23(map, tv, tv_count, tvn, x, y, 3, 1, count, N, M);
			if (t_ans < answer) answer = t_ans;
			
			t_ans = seeTv23(map, tv, tv_count, tvn, x, y, 1, 2, count, N, M);
			if (t_ans < answer) answer = t_ans;

			t_ans = seeTv23(map, tv, tv_count, tvn, x, y, 2, 0, count, N, M);
			if (t_ans < answer) answer = t_ans;
		}
		else {
			copyTable(temp, map, N, M);
			t_ans = seeTvOther(temp, tv, tv_count, tvn - 1, 0, N, M);
			if (t_ans < answer) answer = t_ans;
		}
		return answer;
	}
	else if (tvn == 1) {		
		if (count < tv_count[tvn]) {
			t_ans = seeTv23(map, tv, tv_count, tvn, x, y, 0, 1, count, N, M);
			if (t_ans < answer) answer = t_ans;

			t_ans = seeTv23(map, tv, tv_count, tvn, x, y, 2, 3, count, N, M);
			if (t_ans < answer) answer = t_ans;
		}	
		else {
			copyTable(temp, map, N, M);
			t_ans = seeTvOther(temp, tv, tv_count, tvn - 1, 0, N, M);
			if (t_ans < answer) answer = t_ans;
		}
		return answer;
	}
	else if (tvn == 0) {
		if (count < tv_count[tvn]) {
			for (int i = 0; i < 4; i++) {
				copyTable(temp, map, N, M);
				seeMapOneDirection(temp, x, y, i, N, M);
				t_ans = seeTvOther(temp, tv, tv_count, tvn, count + 1, N, M);
				if (t_ans < answer) answer = t_ans;
			}
		}
		else {
			copyTable(temp, map, N, M);
			t_ans = countSave(temp, N, M);
			if (t_ans < answer) answer = t_ans;
		}
		return answer;
	}
	
	if (tv_count[tvn] == 0) {
		if(tvn == 0) {
			answer = countSave(map, N, M);
			return answer;
		}
		else return seeTvOther(map, tv, tv_count, tvn - 1,  0, N, M);
	}
}

int watch(int map[MAX][MAX], int tv[CTV][MAX][2], int tv_count[CTV], int N, int M) {
	seeTv5(map, tv[4], tv_count[4], N, M);

	int answer = 0;
	answer = seeTvOther(map, tv, tv_count, 3, 0, N, M);

	return answer;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	int map[MAX][MAX];
	memset(map, -1, sizeof(map));
	int tv[CTV][MAX][2];
	memset(tv, -1, sizeof(tv));
	int tv_count[CTV] = { 0, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] > 0 && map[i][j] < 6) {
				int tvn = map[i][j] - 1;
				tv[tvn][tv_count[tvn]][0] = j;
				tv[tvn][tv_count[tvn]][1] = i;
				tv_count[tvn]++;
			}
		}
	}
	
	int answer = watch(map, tv, tv_count, N, M);

	printf("%d", answer);

	return 0;
}