#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
#pragma warning (disable : 4996)

int main() {
	string s;
	getline(cin, s);
	int answer = 0;
	bool flag = true;
	for (int i = 0; i < s.length(); i++) {
		if (flag && s[i] != ' ') {
			answer++;
			flag = false;
		}
		if (s[i] == ' ') flag = true;
	}
	printf("%d", answer);
	return 0;
}