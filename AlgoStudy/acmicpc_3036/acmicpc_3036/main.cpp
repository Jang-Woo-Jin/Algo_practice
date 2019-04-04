#include <stdio.h>
#include <vector>

using namespace std;
#pragma warning(disable : 4996)

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int main() {
	int num;
	scanf("%d", &num);
	vector<int> ring;
	for (int i = 0; i < num; i++) {
		int temp;
		scanf("%d", &temp);
		ring.push_back(temp);
	}
	int first = ring.at(0);
	for (int i = 1; i < num; i++) {
		int div = gcd(ring.at(i), first);
		printf("%d/%d\n", first / div, ring.at(i) / div);
	}
	return 0;
}