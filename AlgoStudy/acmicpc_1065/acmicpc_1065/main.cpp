#include <stdio.h>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int main() {
	int num;
	scanf("%d", &num);

	int answer = 0;
	if (num < 100) answer = num;
	else {
		answer += 99;
		vector<int> numbers;
		for (int i = 1; i < 10; i++) {
			for (int j = 1; j < 5; j++) {
				if (i + 2 * j < 10) numbers.push_back(i * 100 + (i + j) * 10 + i + (2 * j));
				if (i - 2 * j >= 0) numbers.push_back(i * 100 + (i - j) * 10 + i - (2 * j));
			}
			numbers.push_back(i * 100 + i * 10 + i);
		}
		sort(numbers.begin(), numbers.end());
		for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++) {
			if (num >= *iter) answer++;
			else break;
		}
	}
	printf("%d", answer);
	return 0;
}