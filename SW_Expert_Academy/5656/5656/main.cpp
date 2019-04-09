#include <iostream>
#include <stdio.h>
#include <vector>

#pragma warning (disable : 4996)
using namespace std;

#define  MAXW 12
#define  MAXH 15
#define MAXN 4

void deleteBlock(int blocks[MAXH][MAXW], int x, int y, int max_x, int max_y) {
	int size = blocks[y][x];
	blocks[y][x] = 0;
	for (int i = 1; i <	size; i++) {
		if (x - i >= 0) deleteBlock(blocks, x - i, y, max_x, max_y);
		if (x + i < max_x) deleteBlock(blocks, x + i, y, max_x, max_y);
		if (y - i >= 0) deleteBlock(blocks, x, y - i, max_x, max_y);
		if (y + i < max_y) deleteBlock(blocks, x, y + i, max_x, max_y);
	}
}

void reassembleBlock(int blocks[MAXH][MAXW], int max_x, int max_y) {
	int check_line[MAXH] = { 0, };
	int top = 0;
	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++) {
			if (blocks[j][i] != 0) check_line[top++] = blocks[j][i];
		}
		for (int j = max_y - 1; j >= 0; j--) {
			if (top == 0) blocks[j][i] = 0;
			else {
				blocks[j][i] = check_line[--top];
				check_line[top] = 0;
			}
		}
	}
}

void copyTable(int temp[MAXH][MAXW], int blocks[MAXH][MAXW], int W, int H) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			temp[i][j] = blocks[i][j];
		}
	}
}

bool compareTable(int temp[MAXH][MAXW], int blocks[MAXH][MAXW], int W, int H) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (temp[i][j] != blocks[i][j]) return false;
		}
	}
	return true;
}

int countBlock(int blocks[MAXH][MAXW], int W, int H) {
	int answer = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if(blocks[i][j] > 0) answer++;
		}
	}
	return answer;
}

void findFirstBlocks(int blocks[MAXH][MAXW], int firstBlocks[MAXW], int W, int H) {
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			if (blocks[j][i] != 0) {
				firstBlocks[i] = j;
				break;
			}
		}
	}
}

int breakBlocks(int blocks[MAXH][MAXW], int W, int H, int count, int N) {
	int check = countBlock(blocks, W, H);

	if (count == N || check == 0) {
		return check;
	}

	int top = 0;
	int temp[MAXW][MAXH][MAXW] = { 0, };
	int blockCount[MAXW] = { 0, };
	int firstBlocks[MAXW] = { 0, };

	for (int i = 0; i < MAXW; i++) {
		firstBlocks[i] = -1;
	}
	findFirstBlocks(blocks, firstBlocks, W, H);
	for (int i = 0; i < MAXW; i++) {
		if (firstBlocks[i] == -1) continue;
		else {
			copyTable(temp[top], blocks, W, H);
			deleteBlock(temp[top], i, firstBlocks[i], W, H);
			reassembleBlock(temp[top], W, H);
			
			bool compareTest = false;
			for (int j = 0; i < top; i++) {
				for (int m = j + 1; m < top; m++) {
					if (compareTable(temp[j], temp[m], W, H)) {
						compareTest = true;
						break;
					}
				}
				if (compareTest) break;
			}
			if (compareTest) top--;
			else {
				blockCount[top] = breakBlocks(temp[top++], W, H, count + 1, N);
			}
		}
	}
	int answer = 1000;
	for (int i = 1; i <= top; i++) {
		if (answer > blockCount[i]) answer = blockCount[i];
	}
	return answer;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, W, H;
		int blocks[MAXH][MAXW] = { 0, };
		scanf("%d %d %d", &N, &W, &H);
		
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &blocks[i][j]);
			}
		}
	
		int answer = breakBlocks(blocks, W, H, 0, N);
		
		printf("%d\n", answer);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}