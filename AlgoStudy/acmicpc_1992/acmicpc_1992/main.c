/*
#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable: 4996)
void push(int x, int y, int size);


char stack[10000][3] = { 0, };
int top = 0;

int main() {
	int plain[64][64] = { 0, };
	int size;

	scanf("%d", &size);
	
	for (int i = 0; i < size; i++) {
		int temp;
		scanf("%d", &temp);
		for (int j = 0; j < size; j++) {
			plain[i][size - j - 1] = temp % 10;
			temp /= 10;
		}
	}
	
	push(0, 0, size);

	char answer_stack[10000] = { 0, };
	int answer_top = 0;

	while (top > 0) {
		char posx = stack[--top][0];
		char posy = stack[top][1];
		int nsize = stack[top][2];
		int flag = 1;

		if (posx == ')') {
			answer_stack[answer_top++] = ')';
			continue;
		}
		for (int i = posx; i < (posx + nsize); i++) {
			for (int j = posy; j < (posy + nsize); j++) {
				flag = 1;
				if (plain[posx][posy] != plain[i][j]) {
					answer_stack[answer_top++] = '(';
					
					stack[top++][0] = ')';
					push(posx + nsize / 2, posy + nsize / 2, nsize / 2);
					push(posx + nsize / 2, posy, nsize / 2);
					push(posx, posy + nsize / 2, nsize / 2);
					push(posx, posy, nsize / 2);
					
					flag = 0;
					break;
				}
			}
			if (!flag) {
				break;
			}
		}
		
		if (flag) {
			answer_stack[answer_top++] = plain[posx][posy] + '0';
		}
	}

	
	for (int i = 0; i < answer_top; i++) {
		printf("%c", answer_stack[i]);
	}
	
	return 0;
}

void push(int x, int y, int size) {
	stack[top][0] = x;
	stack[top][1] = y;
	stack[top++][2] = size;
}
*/

#include <stdio.h>
#pragma warning(disable : 4996)
int n;
char board[66][66];

void qt(int x, int y, int len)
{
	char first = board[x][y];
	for (int i = x; i < x + len; ++i) {
		for (int j = y; j < y + len; ++j) {
			if (first != board[i][j]) {
				printf("(");
				qt(x, y, len / 2);
				qt(x, y + len / 2, len / 2);
				qt(x + len / 2, y, len / 2);
				qt(x + len / 2, y + len / 2, len / 2);
				printf(")");
				return;
			}
		}
	}
	printf("%c", first);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%s", board[i]);
	qt(0, 0, n);
}