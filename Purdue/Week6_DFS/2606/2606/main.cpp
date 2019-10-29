#include <stdio.h>
#pragma warning (disable : 4996)

void search(int num, bool connections[101][101], bool visited[101], int size) {
	for (int i = 1; i <= size; i++) {
		if (connections[num][i] && !visited[i]) {
			visited[i] = true;
			search(i, connections, visited, size);
		}
	}
}

int main() {
	int computer;
	scanf("%d", &computer);

	int connectionNum;
	scanf("%d", &connectionNum);

	bool connections[101][101] = { false };
	for (int i = 0; i < connectionNum; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		connections[a][b] = connections[b][a] = true;
	}

		bool visited[101] = { false };
	visited[1] = true;
	search(1, connections, visited, computer);
	int answer = 0;
	for (int i = 0; i <= computer; i++) {
		if (visited[i]) answer++;
	}
	printf("%d", answer - 1);
	return 0;
}