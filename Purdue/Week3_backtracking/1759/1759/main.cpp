#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

#pragma warning (disable : 4996)

using namespace std;

const char vowel[5] = { 'a', 'e', 'i', 'o', 'u' };

bool checkVowel(char alpha) {
	for (int i = 0; i < 5; i++) {
		if (alpha == vowel[i]) return true;
	}
	return false;
}

void makePw(char alpha[15], string answer, int length, int vowelNum, int index, int L, int C) {
	if (L == length) {
		if ((vowelNum >= 1) && (length - vowelNum >= 2)) cout << answer << endl;
		return;
	}
	for (int i = index; i < C; i++) {
		string s = answer;
		s += alpha[i];
		if (checkVowel(alpha[i])) makePw(alpha, s, length + 1, vowelNum + 1, i + 1, L, C);
		else makePw(alpha, s, length + 1, vowelNum, i + 1, L, C);
	}
}

int main() {
	int L, C;
	scanf("%d %d\n", &L, &C);

	string s;
	getline(cin, s);

	char alpha[15] = { 0, };
	for (int i = 0; i < C; i++) alpha[i] = s[i * 2];
	
	sort(alpha, alpha + C);

	string answer = "";
	makePw(alpha, answer, 0, 0, 0, L, C);
	return 0;
}