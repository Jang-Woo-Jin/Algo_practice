#include <stdio.h>
#include <algorithm>
#pragma warning(disable : 4996)

int map[9][9] = { 0, };
bool holeTest[81];
std::pair<int, int> holes[81];


void sudoku(int holeNum, int &remainNum) {
	if (remainNum <= 0) return;

	
	bool test[10] = { 0, };

	int x = holes[holeNum].first, y = holes[holeNum].second;
	int sx = (x / 3) * 3, sy = (y / 3) * 3;

	for (int j = 0; j < 9; j++) test[map[x][j]] = test[map[j][y]] = true;

	for (int m = sx; m < sx + 3; m++) for (int n = sy; n < sy + 3; n++) test[map[m][n]] = true;

	for (int j = 1; j < 10; j++) {
		if (!test[j]) {
			map[x][y] = j;
			remainNum--;
			sudoku(holeNum + 1, remainNum);
			if (remainNum <= 0) return;
			else {
				remainNum++;
				map[x][y] = 0;
			}
		}
	}
}

int main() {
	
	int holeNum = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) {
				holes[holeNum].first = i;
				holes[holeNum].second = j;
				holeTest[holeNum++] = false;
			}
		}
	}

	sudoku(0, holeNum);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}