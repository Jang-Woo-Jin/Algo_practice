#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

int map[101][101] = { 0, };
int visited[101][101] = { 0, };
int queueX[10001] = { 0, };
int queueY[10001] = { 0, };
int top = 0, rear = 0;

int vtop, vrear, vvisit;
int vx, vy;

void search(int x, int y);

int main() {
	int x, y;

	scanf("%d %d", &x, &y);

	char num[100];
	for (int i = 1; i <= x; i++) {
		
		scanf("%s", &num);
		
		for (int j = 1; j <= y; j++) {
			int test = num[y - j] - 48;
			if (test) {
				map[i][y - j + 1] = 1;
			}
		}
	}
	
	vtop = top;
	top++;
	queueX[vtop] = 1;
	queueY[vtop] = 1;
	visited[1][1] = 1;
	
	while (top > rear) {
		vrear = rear++;
		
		vx = queueX[vrear];
		vy = queueY[vrear];
		vvisit = visited[vx][vy];

		if (vx - 1 >= 1 && map[vx - 1][vy] == 1) {
			search(vx - 1, vy);
		}
		if (vx + 1 <= x && map[vx + 1][vy] == 1) {
			search(vx + 1, vy);
		}
		if (vy - 1 >= 1 && map[vx][vy - 1] == 1) {
			search(vx, vy - 1);
		}
		if (vy + 1 <= y && map[vx][vy + 1] == 1) {
			search(vx, vy + 1);
		}
	}

	printf("%d", visited[x][y]);
	return 0;
}

void search(int x, int y) {	
	if (visited[x][y] == 0 || visited[x][y] > vvisit) {
		vtop = top++;
		queueX[vtop] = x;
		queueY[vtop] = y;
		visited[x][y] = vvisit + 1;
	}
}
