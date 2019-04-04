#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main() {
	
	int degree, x, y;
	scanf("%d %d %d", &degree, &x, &y);

		
	int size = 1;
	
	for (int i = 0; i < degree; i++) size *= 2;
		
	int answer = 0;
		
	while (size > 2) {
		int hs = size / 2;	
		if (x < hs && y < hs) {
			answer += 0;
		}
		else if (x < hs && y >= hs) {
			answer += hs * hs;
			y -= hs;
		}
		else if (x >= hs && y < hs) {
			answer += hs * hs * 2;
			x -= hs;
		}
		else {
			answer += hs * hs * 3;
			x -= hs; y -= hs;
		}
		size /= 2;
	}
	if (x == 0 && y == 1) answer += 1;
	else if (x == 1 && y == 0) answer += 2;
	else if (x == 1 && y == 1) answer += 3;

	printf("%d\n", answer);
	
	return 0;
}
