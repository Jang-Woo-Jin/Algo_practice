#include <stdio.h>
#pragma warning(disable : 4996)

void bfsSearch(int vertex);
void dfsSearch(int vertex);

int vertex_num, line_num, start_vertex;
int graph[1001][1001] = { 0, };

int queue[1001] = { 0, };
int queue_top = 0, queue_rear = 0;

int visit_bfs[1001] = { 0, };
int visit_dfs[1001] = { 0, };

int main() {
	scanf("%d %d %d", &vertex_num, &line_num, &start_vertex);

	for (int i = 0; i < line_num; i++) {
		int start, end;
		scanf("%d %d", &start, &end);
		graph[start][end] = 1;
		graph[end][start] = 1;
	}
	
	dfsSearch(start_vertex);
	printf("\n");
	bfsSearch(start_vertex);
	
	return 0;
}

void dfsSearch(int input) {
	int vertex = input;

	if (visit_dfs[vertex] != 1) {
		printf("%d ", vertex);
		visit_dfs[vertex] = 1;

		for (int i = 1; i <= vertex_num; i++) {
			if (graph[vertex][i] == 1) {
				dfsSearch(i);
			}
		}
	}

	return;
}

void bfsSearch(int input) {
	int vertex = input;
	
	visit_bfs[vertex] = 1;
	queue[queue_top++] = vertex;

	while (queue_top > queue_rear) {
		int v = queue[queue_rear++];
		printf("%d ", v);
		
		for (int i = 1; i <= vertex_num; i++) {
			if (graph[v][i] == 1 && visit_bfs[i] != 1) {
				visit_bfs[i] = 1;
				queue[queue_top++] = i;
			}
		}
	}

	return;
}