#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)

int main() {
	int num;
	scanf("%d", &num);

	long long fibo[100];
	memset(fibo, -1, 100);

	fibo[0] = 0; fibo[1] = 1;
	for (int i = 2; i <= num; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	printf("%lld", fibo[num]);
	return 0;
}