#include <stdio.h>

#pragma warning (disable : 4996)

int main() {
	int size;
	scanf("%d", &size);

	int num[1000] = { 0, };
	for (int i = 0; i < size; i++) {
		scanf("%d", &num[i]);
	}
	
	int table[1000] = { 0, };
	return 0;
}