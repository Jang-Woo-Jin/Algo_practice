#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n - lost.size();
	int size = lost.size() + reserve.size();
	int list[32];
	for(int i = 0; i < n; i++) list[i] = 0;

	for (int i = 0; i < lost.size(); i++) list[lost.at(i) - 1] = -1;
	for (int i = 0; i < reserve.size(); i++) {
		if (list[reserve.at(i) - 1] == -1){
			list[reserve.at(i) - 1] = 0;
			answer++;
		}
		else list[reserve.at(i) - 1] = 1;
	}
	for (int i = 0; i < size; i++) {
		if (list[i] == -1) {
			if (i > 0 && list[i - 1] == 1) {
				list[i - 1] = 0;
				answer++;
			}
			else if (list[i + 1] == 1) {
				list[i + 1] = 0;
				answer++;
				i++;
			}
		}
	}
	return answer;
}

int main() {
	int size = 5;
	vector<int> lost = {2, 4};
	vector<int> reserve = {1, 3};


	int answer = solution(size, lost, reserve);
	printf("%d", &answer);
	return 0;
}