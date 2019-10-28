#include <stdio.h>
#include <queue>
#pragma warning(disable : 4996)

int main() {
	int start, end;
	scanf("%d %d", &start, &end);

	std::queue<int> q;
	int position[200000] = { 0, };
	q.push(start);
	position[start]++;

	while (!q.empty()) {	
		int current = q.front();
		q.pop();

		if (current == end) {
			printf("%d", position[current] - 1);
			break;
		}
		int way[3];
		way[0] = current - 1;
		way[1] = current + 1;
		way[2] = current * 2;
		for (int i = 0; i < 3; i++) {
			if (way[i] > -1 && way[i] < 2000000&& position[way[i]] == 0) {
				q.push(way[i]);
				position[way[i]] = position[current] + 1;
			}
			
		}
	}
	return 0;
}