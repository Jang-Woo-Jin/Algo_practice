#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
#pragma warning (disable : 4996)

int main() {
	int size;
	scanf("%d", &size);

	int numbers[100001];
	int dp_table[100001];

	for (int i = 0; i < size; i++) {
		scanf("%d", &numbers[i]);
	}

	dp_table[0] = numbers[0];
	dp_table[1] = numbers[0] + numbers[1];
	dp_table[2] = max(numbers[0] + numbers[2], dp_table[1]);

	for (int i = 3; i < size; i++) {
		dp_table[i] = max(numbers[i] + numbers[i - 1] + dp_table[i - 3], numbers[i] + dp_table[i - 2]);
		dp_table[i] = max(dp_table[i], dp_table[i - 1]);
	}

	printf("%d", dp_table[size - 1]);
	return 0;
}