#include <stdio.h>

#pragma warning (disable : 4996)

int paper[2187][2187] = { 0, };

int flag;
int answer[3] = { 0, };
int stack[4782969][3] = { 0, };
int top = 0;

int main() {
	int size;
	scanf("%d", &size);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			scanf("%d", &paper[i][j]);
		}
	}

	stack[top][0] = 0;
	stack[top][1] = 0;
	stack[top++][2] = size;


	while (top > 0) {
		int pos[3] = { 0, };
		pos[0] = stack[--top][0];
		pos[1] = stack[top][1];
		pos[2] = stack[top][2];
		
		flag = paper[pos[0]][pos[1]];

		for (int i = pos[0]; i < pos[0] + pos[2]; i++) {
			for (int j = pos[1]; j < pos[1] + pos[2]; j++) {
				if (flag != paper[i][j]) {
					int space = pos[2] / 3;
					int x = pos[0];
					int y = pos[1];
					for (int m = 0; m < 3; m++) {
						for (int n = 0; n < 3; n++) {
							stack[top][0] = x + (space * m);
							stack[top][1] = y + (space * n);
							stack[top++][2] = space;
						}
					}
					
					i += 3000;
					j += 3000;
					flag = 2;
				}
			}
		}
		if (flag != 2) answer[flag + 1]++;
	}

	for (int i = 0; i < 3; i++) {
		printf("%d\n", answer[i]);
	}
	return 0;
}