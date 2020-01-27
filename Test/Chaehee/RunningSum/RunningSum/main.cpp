#include <stdio.h>

#pragma warning (disable : 4996)

int main() {

	int n = 0;
	scanf("%d", &n);

	int arr[10000] = { 0, };
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int min = 10000;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum < min) min = sum;
	}
	int answer = 0;
	if (min != 0) answer = (min * -1) + 1;
	return answer;
}