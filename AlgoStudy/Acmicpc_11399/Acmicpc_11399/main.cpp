#include <stdio.h>

#pragma warning(disable : 4996)

int main() {
	int num;
	int time[1000];

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &time[i]);
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (time[i] < time[j]) {
				int temp = time[i];
				time[i] = time[j];
				time[j] = temp;
			}
		}
	}

	int answer = 0;
	int elapsed = 0;
	for (int i = 0; i < num; i++) {
		answer += (elapsed + time[i]);
		elapsed += time[i];
	}
	printf("%d", answer);
	return 0;
}