#include <stdio.h>
#include <algorithm>
#pragma warning (disable : 4996)

using namespace std;

int main() {
	int line_num, cut_num;
	scanf("%d %d", &line_num, &cut_num);

	int lines[10000] = { 0, };
	int max_line = 0;
	for (int i = 0; i < line_num; i++) {
		scanf("%d", &lines[i]);
		max_line = max_line > lines[i] ? max_line : lines[i];
	}
	
	int start = 0, end = max_line;
	long long int middle = 0;
	int max = 0;
	while (1) {
		middle = (start + end) / 2;
		int count = 0;
		for (int i = 0; i < line_num; i++) {
			count += (lines[i] / middle);
		}
		if (count >= cut_num) {
			start = middle + 1;
			max = max > middle ? max : middle;
		}
		else end = middle - 1;
		if (middle  == start || middle == end) break;
	}
	printf("%d", max);
	return 0;
}