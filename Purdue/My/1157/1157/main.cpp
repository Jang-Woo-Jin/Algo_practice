#include <stdio.h>
#include <algorithm>
#pragma warning(disable : 4996)

char string[1000000] = { 0, };

int main() {
	scanf("%s", string);
	
	std::pair<int, int> alpha[26];
	for (int i = 0; i < 26; i++) {
		alpha[i].first = 0;
		alpha[i].second = 'A' + i;
	}
	for (int i = 0; i < 1000000; i++) {
		if (string[i] == 0) break;
		if (string[i] - 'a' >= 0) alpha[string[i] - 'a'].first--;
		else alpha[string[i] - 'A'].first--;
	}

	std::sort(alpha, alpha + 26);
	if (alpha[0].first == alpha[1].first) printf("?");
	else printf("%c", alpha[0].second);
	return 0;
}