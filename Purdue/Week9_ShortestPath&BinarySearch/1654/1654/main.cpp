#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	int line_num, cut_num;
	scanf("%d %d", &line_num, &cut_num);

	int lines[10000] = { 0, };
	int max_line = 0;
	for (int i = 0; i < line_num; i++) {
		scanf("%d", &lines[i]);
		max_line = max_line > lines[i] ? max_line : lines[i];
	}
	
	long long int start = 0, end = max_line;
	long long int middle = 0;
	int max = 0;
	while (start <= end) {
		middle = (start + end + 1) / 2;
		int count = 0;
		for (int i = 0; i < line_num; i++) {
			count += (lines[i] / middle);
		}
		if (count >= cut_num) {
			max = middle;
			start = middle + 1;
		}
		else end = middle - 1;
	}
	printf("%d", max);
	return 0;
}