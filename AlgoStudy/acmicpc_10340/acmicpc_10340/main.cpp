#include <stdio.h>

#pragma warning (disable : 4996)

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	int answer[4];
	answer[0] = (a + b) % c;
	answer[1] = answer[0] % c;
	answer[2] = (a * b) % c;
	answer[3] = answer[2] % c;

	for (int i = 0; i < 4; i++) {
		printf("%d\n", answer[i]);
	}
	return 0;
}