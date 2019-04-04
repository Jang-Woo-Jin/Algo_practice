#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable : 4996)

int num[100000][2] = { 0, };

int main() {
	int size;
	scanf("%d", &size);
	
	for (int i = 0; i < size; i++) {
		scanf("%d", &num[i][0]);
	}
	
	int answer = 0;
	
	answer = num[0][1] = num[0][0];
	
	for (int i = 1; i < size; i++) {
		if (num[i - 1][1] > 0) num[i][1] = num[i][0] + num[i - 1][1];
		else num[i][1] = num[i][0];

		if (num[i][1] > answer) answer = num[i][1];
	}
	printf("%d", answer);

	return 0;
}