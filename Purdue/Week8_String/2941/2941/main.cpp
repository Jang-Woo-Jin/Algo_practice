#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#pragma warning (disable : 4996)

const string cro[7] = {"c=", "c-", "d-", "lj", "nj", "s=", "z="};

int main() {
	string s;
	getline(cin, s);

	int list[8] = { 0, };
	int index[7] = { 0, };
	for(int i = 0; i < s.length(); i++){
		for (int j = 0; j < 7; j++) {
			if (s[i] == cro[j][index[j]]) {
				index[j]++;
				if (index[j] == cro[j].length()) {
					if (j == 6 && i > 2 && s[i - 2] == 'd') {
						list[7]++;
					}
					else {
						list[j]++;
					}
					index[j] = 0;
				}
			}
			else {
				index[j] = 0;
			}
		}
	}
	int answer = s.length();
	for (int i = 0; i < 7; i++) {
		answer += list[i];
		answer -= list[i] * cro[i].length();
	}
	answer += list[7];
	answer -= list[7] * 3;
	printf("%d", answer);
	return 0;
}