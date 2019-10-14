#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

#pragma warning (disable : 4996)

using namespace std;

class Question
{
public:
	int deadline;
	int cup;
	bool used = false;
	Question() {}
	Question(int deadline, int cup) : deadline(deadline), cup(cup) {}

	bool operator < (const Question &comp) const {
		if (deadline == comp.deadline) return (cup < comp.cup);
		return (deadline < comp.deadline);
	}
};

//Question questions[200000];

int main() {
	int size;
	scanf("%d", &size);

	Question questions[200];
	for (int i = 0; i < size; i++) {
		int deadline, cup;
		scanf("%d %d", &deadline, &cup);
		questions[i] = Question(deadline, cup);
	}

	sort(questions, questions + size);
	
	int answer = 0;
	priority_queue<int> pq;

	for (int i = 1; i < size; i++) {
		answer += questions[i].cup;
		pq.push(-questions[i].cup);
		while (pq.size() > questions[i].deadline) {
			answer += pq.top();
			pq.pop();
		}
	}
	printf("%d", answer);
	return 0;
}