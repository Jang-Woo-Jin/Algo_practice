#include <stdio.h>
#include <math.h>

#pragma warning (disable : 4996)

int main() {
	int num;

	scanf("%d", &num);

	int answer[1001] = { 0, };
	answer[0] = 1;

	for (int i = 1; i < num; i++) {
		answer[i] = ((answer[i - 1] * 2) + (int)(pow(-1, i + 1))) % 10007;
	}
	printf("%d", answer[num - 1]);
	
	return 0;
}