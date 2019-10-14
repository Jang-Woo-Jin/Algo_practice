#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
#pragma warning (disable : 4996)

int main() {
	int size;
	scanf("%d", &size);
	
	int num1[50];
	int num2[50];

	memset(num1, 0, 50);
	memset(num2, 0, 50);

	for (int i = 0; i < size; i++) scanf("%d", &num1[i]);
	for (int i = 0; i < size; i++) scanf("%d", &num2[i]);

	sort(num1, num1 + size);
	sort(num2, num2 + size);

	int answer = 0;
	for (int i = 0; i < size; i++) {
		answer += num1[i] * num2[size - 1 - i];
	}
	printf("%d\n", answer);
	return 0;
}