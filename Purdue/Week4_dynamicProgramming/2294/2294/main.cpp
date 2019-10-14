#include <stdio.h>
#include <string.h>
#include <queue>
#pragma warning (disable : 4996)

int main() {
	int N, K;
	int coins[101] = { 0, };
	int table[10001];
	
	scanf("%d %d", &N, &K);
	memset(table, -1, sizeof(int) * (K + 1));
	for (int i = 0; i < N; i++) {
		scanf("%d", &coins[i]);
		if(coins[i] <= 10000) table[coins[i]] = 1;
	}

	for (int i = 2; i <= K; i++) {
		std::priority_queue<int> pq;
		if (table[i] == -1) {
			for (int j = 1; j <= i / 2; j++) {
				if (table[i - j] != -1 && table[j] != -1) pq.push((table[i - j] + table[j]) * -1);
			}
			if (pq.size() > 0) table[i] = pq.top() * -1;
		}
	}
	printf("%d", table[K]);
	return 0;
}