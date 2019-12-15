#include <stdio.h>
#include <string.h>
#include <queue>

#pragma warning(disable : 4996)

using namespace std;

int path[1001][1001];
int weight[1001][1001];

int main() {
	int num[1001] = { 0, };
	memset(path, -1, sizeof(int) * 1001 * 1001);
	memset(weight, -1, sizeof(int) * 1001 * 1001);

	int C, B, S, E; // City, Bus, Start, End
	scanf("%d", &C);
	scanf("%d", &B);

	for (int i = 0; i < B; i++) {
		int c1, c2, fee;
		scanf("%d %d %d", &c1, &c2, &fee);
		path[c1][num[c1]] = c2;	
		num[c1]++;
		weight[c1][c2] = fee;
	}
	scanf("%d %d", &S, &E);

	priority_queue<pair<int,int>> q;
	int distance[1001] = { 0, };
	
	
	q.push(pair<int, int>(distance[S], S));

	while (!q.empty()) {
		pair<int, int> node = q.top();
		q.pop();
		int from = node.second;
		for (int i = 0; i < num[from]; i++) {
			int to = path[from][i];
			if (distance[to] == 0 || distance[to] < node.first - weight[from][to]) {
				distance[to] = node.first - weight[from][to];
				q.push(pair<int, int>(distance[to], to));
			}
		}
	}
	printf("%d", distance[E] * -1);
	return 0;
}