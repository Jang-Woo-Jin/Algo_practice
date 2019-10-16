#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>

#pragma warning(disable : 4996);

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int answer1[5] = { 1, 2, 3, 4, 5 };
	int answer2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
	int answer3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	pair<int, int> corrects[3];
	for (int i = 0; i < 3; i++) {
		corrects[i].first = 0;
		corrects[i].second = i + 1;
	}
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == answer1[i % 5]) corrects[0].first--;
		if (answers[i] == answer2[i % 8]) corrects[1].first--;
		if (answers[i] == answer3[i % 10]) corrects[2].first--;
	}
	sort(corrects, corrects + 3);
	answer.push_back(corrects[0].second);
	for (int i = 0; i < 2; i++) {
		if (corrects[i].first == corrects[i + 1].first) {
			answer.push_back(corrects[i + 1].second);
		}
		else break;
	}
	return answer;
}

int main() {
	vector<int> answers;
	
	for (int i = 0; i < 10; i++) {
		int num;
		scanf("%d", &num);
		answers.push_back(num);
	}
	vector<int> solutions = solution(answers);
	return 0;
}