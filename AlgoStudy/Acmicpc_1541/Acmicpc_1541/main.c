#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

int main() {
	char string[50] = { 0, };
	int num[50] = { 0, };
	char op[50] = { 0, };

	scanf("%s", &string);
	
	int stringLength = 0;
	int maxNum = 0;
	int maxOp = 0;

	int length = 0;
	for (int i = 0; i < 50; i++) {
		if (string[i] != 0) {
			if (string[i] != '+' && string[i] != '-') {
				length++;
			}
			else {
				op[maxOp++] = string[i];
				for (int j = length; j > 0; j--) {
					int size = 1;
					for (int k = 1; k < j; k++) {
						size *= 10;
					}
					num[maxNum] += (string[i - j] - '0') * size;
				}
				maxNum++;
				length = 0;
			}
			stringLength++;
		}
		else {
			for (int j = length; j > 0; j--) {
				int size = 1;
				for (int k = 1; k < j; k++) {
					size *= 10;
				}
				num[maxNum] += (string[i - j] - '0') * size;
			}
			maxNum++;
			length = 0;
			break;
		}
	}

	int maxPaNum = (50 - stringLength) / 2;

	int minusPos[50] = { 0, };
	int minusNum = 0;
	for (int i = 0; i < maxOp; i++) {
		if (op[i] == '-') {
			minusPos[minusNum++] = i;
		}
	}
	minusPos[minusNum] = maxNum - 1;

	int sumNum[50] = { 0, };
	for (int i = 0; i < minusNum; i++) {
		for (int j = minusPos[i] + 1; j <= minusPos[i + 1]; j++) {
			sumNum[i] += num[j];
		}
	}
	
	int sumPos[50] = { 0, };
	for (int i = 0; i < 50; i++) sumPos[i] = i;
	
	int tempArray[50];
	for (int i = 0; i < maxNum; i++) tempArray[i] = sumNum[i];
	
	for (int i = 0; i < minusNum; i++) {
		for (int j = 0; j < minusNum; j++) {
			if (tempArray[i] > tempArray[j]) {
				int temp = sumPos[i];
				sumPos[i] = sumPos[j];
				sumPos[j] = temp;

				temp = tempArray[i];
				tempArray[i] = tempArray[j];
				tempArray[j] = temp;
			}
		}
	}

	for(int i = 0; i< maxPaNum && i< minusNum; i++){

		int pos = sumPos[i];
		for (int j = minusPos[pos] + 1; j <= minusPos[pos + 1]; j++) {
			if (j == minusPos[pos] + 1) num[j] = sumNum[pos];
			else num[j] = 0;
		}
	}

	int answer = num[0];
	for (int i = 0; i < maxOp; i++) {
		if (op[i] == '+') answer += num[i + 1];
		else answer -= num[i + 1];
	}

	printf("%d", answer);
	return 0;
}