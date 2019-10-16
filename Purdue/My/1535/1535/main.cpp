#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)

int main() {
	int num;
	int happy[20], life[20];
	memset(happy, -1, sizeof(int) * 20);
	memset(life, -1, sizeof(int) * 20);
	
	scanf("%d", &num);
	for (int i = 0; i < num; i++) scanf("%d", &life[i]);
	for (int i = 0; i < num; i++) scanf("%d", &happy[i]);
	
	int maxLife = 100;
	int happy = 0;

	return 0;
}