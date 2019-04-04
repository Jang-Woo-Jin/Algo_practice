#include <stdio.h>
#include <algorithm>

#pragma warning (disable : 4996)

int meeting[100000][2] = { 0, };
int time[100000] = { 0, };
int answer[100000] = { 0, };
int sorted[100000][2] = { 0, };

void merge_sort(int list[], int left, int right);
void merge(int list[], int left, int mid, int right);

int main() {
	int num = 0;
	

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d %d", &meeting[i][0], &meeting[i][1]);
		time[i] = meeting[i][1] - meeting[i][0];
		sorted[i][1] = i;
	}
	
	merge_sort(time, 0, num - 1);
	
	int count = 0;
	answer[count++] = sorted[0][1];
	for (int i = 1; i < num; i++) {
		answer[count++] = sorted[i][1];
		for (int j = 0; j < count - 1; j++) {
			if (!(meeting[answer[j]][0] >= meeting[sorted[i][1]][1] || meeting[answer[j]][1] <= meeting[sorted[i][1]][0])) {
				count--;
				break;
			}
		}
	}
	printf("%d", count);
	
	return 0;
}

void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) {
			sorted[k][1] = j;
			sorted[k++][0] = list[i++];
		}
		else {
			sorted[k][1] = j;
			sorted[k++][0] = list[j++];
		}
	}

	if (i > mid) {
		for (l = j; l <= right; l++) {
			sorted[k][1] = l;
			sorted[k++][0] = list[l];
		}
	}
	else {
		for (l = i; l <= mid; l++) {
			sorted[k][1] = l;
			sorted[k++][0] = list[l];
		}
	}

	for (l = left; l <= right; l++) {
		list[l] = sorted[l][0];
	}
}

void merge_sort(int list[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}
