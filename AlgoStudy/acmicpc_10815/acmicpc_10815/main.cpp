#include <stdio.h>
#include <algorithm>
#include <vector>
#include<list>

using namespace std;
#pragma warning(disable : 4996)

typedef struct myNum {
	int x;
	int key;
}_myNum;

bool compareMyNum(_myNum x, _myNum y) {
	return x.x < y.x;
}

int main() {
	int num1, num2;
	scanf("%d", &num1);

	list<int> numlist1;
	list<_myNum> numlist2;

	int temp;
	for (int i = 0; i < num1; i++) {
		scanf("%d", &temp);
		numlist1.push_back(temp);
	}
	numlist1.sort();

	scanf("%d", &num2);
	_myNum myTemp;
	for (int i = 0; i < num2; i++) {
		scanf("%d", &temp);
		myTemp.x = temp;
		myTemp.key = i;
		numlist2.push_back(myTemp);
	}

	numlist2.sort(compareMyNum);

	int *answer;
	answer = (int*)malloc(sizeof(int) * num2);

	list<int>::iterator iter1;
	list<_myNum>::iterator iter2;
	
	
	for (iter2 = numlist2.begin(); iter2 != numlist2.end(); iter2++) {
		for (iter1 = numlist1.begin(); iter1 != numlist1.end();) {
			if (*iter1 > (*iter2).x) {
				answer[(*iter2).key] = 0;
				break;
			}

			if (*iter1 != (*iter2).x) {
				iter1++;
				numlist1.pop_front();
			}
			else {
				iter1++;
				numlist1.pop_front();
				answer[(*iter2).key] = 1;
				break;
			}
		}
	}
	
	for (int i = 0; i < num2; i++) {
		printf("%d ", answer[i]);
	}
	
	return 0;
}