#include <stdio.h>
#include <algorithm>
#pragma warning (disable : 4996)

using namespace std;

int main() {
	int tall[9] = { 0, };
	int total = 0;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &tall[i]);
		total += tall[i];
	}
	
	int sum8[9] = { 0, };
	
	for (int i = 0; i < 9; i++) {
		sum8[i] = total - tall[i];
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (((sum8[i] - tall[j]) == 100) && i != j) {
				tall[i] = tall[j] = 100;
				break;
			}
		}
		if (tall[i] == 100) break;
	}

	sort(tall, tall + 9);
	for (int i = 0; i < 7; i++) {
		printf("%d\n", tall[i]);
	}
	return 0;
}