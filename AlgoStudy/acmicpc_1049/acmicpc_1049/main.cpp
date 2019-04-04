#include <stdio.h>
#include <list>

using namespace std;
#pragma warning (disable : 4996)

int main() {
	int num, brand;
	scanf("%d %d", &num, &brand);

	list<int> sixPrice, onePrice;
	int price6, price1;
	for (int i = 0; i < brand; i++) {
		scanf("%d %d", &price6, &price1);
		sixPrice.push_back(price6);
		onePrice.push_back(price1);
	}

	sixPrice.sort();
	onePrice.sort();

	int low6, low1;
	low6 = sixPrice.front();
	low1 = onePrice.front();

	int answer;
	if (low6 > low1 * 6) answer = low1*num;
	else {
		answer = low6 * (num / 6);
		if (low6 < low1 * (num % 6)) {
			answer += low6;
		}
		else {
			answer += (low1 * (num % 6));
		}
	}
	printf("%d", answer);

	return 0;
}