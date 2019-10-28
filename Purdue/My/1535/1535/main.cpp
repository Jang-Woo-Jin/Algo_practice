#include <stdio.h>
#include <string.h>
#include <algorithm>
#pragma warning (disable : 4996)

int main() {
	int num;
	std::pair<int, int> people[20];
	memset(people, -1, sizeof(std::pair<int, int>) * 20);
	
	scanf("%d", &num);
	for (int i = 0; i < num; i++) scanf("%d", &people[i].first);
	for (int i = 0; i < num; i++) scanf("%d", &people[i].second);
	
	sort(people, people + num);
	
	int table[101][21];
	memset(table, -1, sizeof(int) * 101 * 21);

	for (int i = 0; i < 21; i++) table[0][i] = 0;
	for (int i = 0; i < 101; i++) table[i][0] = 0;
	
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= num; j++) {
			if (people[j - 1].first <= i) {
				int origin = table[i][j - 1];
				int added = table[i - people[j - 1].first][j - 1] + people[j - 1].second;
				table[i][j] = origin > added ? origin : added;

			}
			else {
				table[i][j] = table[i][j - 1];
			}
		}
	}
	if (num > 0) printf("%d", table[99][num]);
	else printf("0");
	return 0;
}