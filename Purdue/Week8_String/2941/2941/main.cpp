#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#pragma warning (disable : 4996)

const string cro[3] = {"lj", "nj", "dz="};

int main() {
	string s;
	getline(cin, s);

	int index[3] = { 0, };
	int answer = 0;
	for(int i = 0; i < s.length(); i++){
		if (s[i] >= 'a' && s[i] <= 'z') answer++;
		if (s[i] == 'j' && (s[i - 1] == 'n' || s[i - 1] == 'l')) answer--;
		if (s[i] == 'z' && s[i - 1] == 'd' && s[i + 1] == '=') answer--;
	}
	printf("%d", answer);
	return 0;
}