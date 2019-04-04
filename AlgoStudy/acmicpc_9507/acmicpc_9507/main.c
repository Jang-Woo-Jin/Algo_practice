#include <stdio.h>

#pragma warning (disable : 4996)

unsigned long long myfibo(int x);
unsigned long long fibotable[100] = { 0, };

int main() {
	fibotable[0] = 1;
	fibotable[1] = 1;
	fibotable[2] = 2;
	fibotable[3] = 4;

	int test_case;
	
	scanf("%d", &test_case);

	for (int i = 0; i < test_case; i++) {
		int fibo;
		scanf("%d", &fibo);
		printf("%llu\n", myfibo(fibo));
	}
}


unsigned long long myfibo(int num) {
	for (int i = 4; i <= num; i++) {
		fibotable[i] = fibotable[i - 4] + fibotable[i - 3] + fibotable[i - 2] + fibotable[i - 1];
	}
	return fibotable[num];
}