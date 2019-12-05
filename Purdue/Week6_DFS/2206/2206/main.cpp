#include <stdio.h>
#include <algorithm>
#include <queue>

#pragma warning (disable : 4996)

using namespace std;

const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };

bool map[1000][1000] = { false };
int visited[1000][1000][2] = { 0, };

class Point {
public:
	int x;
	int y;
	int count;
	Point();
	Point(int x, int y, int count) {
		this->x = x;
		this->y = y;
		this->count = count;
	}
};

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++) {
		scanf("\n");
		for (int j = 0; j < M; j++) {
			char input;
			scanf("%c", &input);
			map[i][j] = input - 48;
		};
	}
	visited[0][0][0] = 1;
	visited[N - 1][M - 1][0] = visited[N - 1][M - 1][1] = -1;
	
	queue<Point> q;
	q.push(Point(0, 0, 1));
	while(!q.empty()){
		Point current = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {

		}
	}
	//printf("%d", visited[N - 1][M - 1][0] < visited[N - 1][M - 1][1] ? visited[N - 1][M - 1][0] : visited[N - 1][M - 1][1]);
	return 0;
}