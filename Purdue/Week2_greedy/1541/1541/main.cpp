#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#pragma warning(disable : 4996)

using namespace std;

#define MAXLENGTH 50

int main() {
	string s;
	cin >> s;

	vector<int> nums;
	vector<int> operators;
	string number;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] < '0' || s[i] > '9') {
			nums.push_back(stoi(number));
			if (s[i] == '+')operators.push_back(1);
			else operators.push_back(-1);
			number = ' ';
		}
		else number += s[i];
	}
	nums.push_back(stoi(number));

	int answer = 0;
	bool minusFlag = false;
	for (int i = 0; i < nums.size(); i++) {
		if (i > 0 && operators[i - 1] == -1) minusFlag = true;
		if (minusFlag) answer -= nums[i];
		else answer += nums[i];
	}
	printf("%d", answer);
	return 0;
}