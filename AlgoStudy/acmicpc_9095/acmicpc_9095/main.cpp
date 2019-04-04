#include <stdio.h>

#pragma warning (disable : 4996)

int main() {
	int test;
	scanf("%d", &test);
	while (test-- > 0) {
		int num;
		scanf("%d", &num);

		int answer[12] = { 0, };
		int add_num[12] = { 0, };
		answer[0] = 0; answer[1] = 1; answer[2] = 2; answer[3] = 4;
		add_num[1] = 0; add_num[2] = 0; add_num[3] = 1;

		for (int i = 4; i <= num; i++) {
			add_num[i] = add_num[i - 1] + add_num[i - 2] + add_num[i - 3];
			answer[i] = answer[i - 1] + answer[i - 2] + add_num[i];
		}

		printf("%d\n", answer[num]);
	}
	return 0;
}