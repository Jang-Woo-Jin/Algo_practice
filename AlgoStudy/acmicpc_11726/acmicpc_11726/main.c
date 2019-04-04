#include <stdio.h>

#pragma warning (disable : 4996)

int main() {
	int num;

	scanf("%d", &num);

	int answer[10000] = { 0, };
	answer[0] = 1;
	answer[1] = 2;

	for (int i = 2; i < num; i++) {
		answer[i] = (answer[i - 2] + answer[i - 1]) % 10007;
	}
	printf("%d", answer[num - 1]);
	
	return 0;
}