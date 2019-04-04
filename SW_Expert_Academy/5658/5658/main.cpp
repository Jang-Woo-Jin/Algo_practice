#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

#pragma warning (disable : 4996)
using namespace std;

int convertHexNum(string numbers) {
	int length = numbers.length();
	int answer = 0;
	int sub = 0;
	for (int i = 0; i < length; i++) {
		if (numbers[i] >= 'A') sub = 'A' -10;
		else sub = '0';
		answer += (numbers[i] - sub) * pow(16, length - 1 - i);
	}
	return answer;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int size, order;
		scanf("%d %d", &size, &order);

		char number_set[30] = { 0, };
		scanf("%s", &number_set);

		vector<int> answer_list;
		//answer_list = (int*)malloc(sizeof(int) * size);

		for (int i = 0; i < size / 4; i++) {
			string temp = number_set;
			for (int j = 0; j < 4; j++) {
				answer_list.push_back(convertHexNum(temp.substr(j * (size / 4), size / 4)));
			}
			char temp_num = number_set[size - 1];
			for (int j = 0; j < size - 1; j++) {
				number_set[size - 1 - j] = number_set[size - 2 - j];
			}
			number_set[0] = temp_num;
		}
		sort(answer_list.begin(), answer_list.end(), greater<int>());
		int count = 1;
		int answer = answer_list.at(0);
		for (vector<int>::iterator iter = answer_list.begin() + 1; iter != answer_list.end(); iter++) {
			if (count == order) {
				break;
			}
			else {
				if (*iter == *(iter - 1)) continue;
				else {
					answer = *iter;
					count++;
				}
			}
		}
		printf("#%d %d\n", test_case, answer);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}