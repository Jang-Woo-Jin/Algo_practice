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
		for (int j = 0; j < 3; j++) {
			if (s[i] == cro[j][index[j]]) {
				index[j]++;
				if (index[j] == cro[j].length()) {
					answer--;
					index[j] = 0;
				}
			}
			else index[j] = 0;
			
		}
	}
	printf("%d", answer);
	return 0;
}