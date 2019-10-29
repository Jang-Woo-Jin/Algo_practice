#include <stdio.h>
#include <string.h>
#include <queue>
#pragma warning (disable : 4996)

using namespace std;

// 동 서 남 북 상 하
const int dx[6] = {1, -1, 0, 0, 0, 0};
const int dy[6] = {0, 0, 1, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, -1, 1};

class Position{
public:
	int x = 0;
	int y = 0;
	int z = 0;

	Position() = default;
	Position(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	};
};

int main() {
	int L, R, C;
	scanf("%d %d %d", &L, &R, &C);
	while (!(L == 0 && R == 0 && C == 0)) {
		scanf("\n");
		char map[30][30][30] = {0, };
		int visited[30][30][30] = { 0, };
		memset(map, 0, sizeof(char) * 30 * 30 * 30);
		memset(visited, 0, sizeof(int) * 30 * 30 * 30);
		Position start, end;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int m = 0; m < C; m++) {
					scanf("%c", &map[i][j][m]);
					if (map[i][j][m] == 'S') start = Position(i, j, m);
					else if (map[i][j][m] == 'E') end = Position(i, j, m);
				}
				scanf("\n");
			}
			scanf("\n"); 
		}

		queue<Position> q;
		q.push(start);
		while (!q.empty()) {
			Position c = q.front();
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nx = c.x + dx[i], ny = c.y + dy[i], nz = c.z + dz[i];
				if (nx > -1 && nx < L && ny > -1 && ny < R && nz > -1 && nz < C) {
					if (visited[nx][ny][nz] == 0 && map[nx][ny][nz] != '#') {
						q.push(Position(nx, ny, nz));
						visited[nx][ny][nz] = visited[c.x][c.y][c.z] + 1;
					}
				}
			}
		}
		if (visited[end.x][end.y][end.z] != 0) printf("Escaped in %d minute(s).\n", visited[end.x][end.y][end.z]);
		else printf("Trapped!\n");

		scanf("%d %d %d", &L, &R, &C);
	}
	return 0;
}