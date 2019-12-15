#include <stdio.h>
#include <algorithm>
#pragma warning (disable : 4996)

using namespace std;

int main() {
	int line_num, cut_num;
	scanf("%d %d", &line_num, &cut_num);

	int lines[10000] = { 0, };
	for (int i = 0; i < line_num; i++) {
		scanf("%d", &lines[i]);
	}
	sort(lines, lines + line_num);

	bool flag = true;
	int num = lines[0];
	int add_num = lines[0];
	int answer = 0;
	while (flag) {
		add_num = (add_num / 2 + add_num % 2);
		int count = 0;
		for (int i = 0; i < line_num; i++) {
			count += (lines[i] / num);
		}
		if (count >= cut_num) {
			if (num == answer) break;
			if (num > answer) answer = num;
			num += add_num;
		}
		else {
			num -= add_num;
		}
	}
	printf("%d", answer);
	return 0;
}