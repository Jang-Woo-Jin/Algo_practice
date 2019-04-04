/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// scanf("%d", &a);                      // int 변수 1개 입력받는 예제
// scanf("%f %f", &b, &c);               // float 변수 2개 입력받는 예제 
// scanf("%lf %lf %lf", &d, &e, &f);     // double 변수 3개 입력받는 예제
// scanf("%c", &g);                      // char 변수 1개 입력받는 예제
// scanf("%s", &var);                    // 문자열 1개 입력받는 예제
// scanf("%lld", &AB);                   // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// printf("%d", a);                      // int 변수 1개 출력하는 예제
// printf("%f %f", b, c);                // float 변수 2개 출력하는 예제
// printf("%lf %lf %lf", d, e, f);       // double 변수 3개 출력하는 예제
// printf("%c", g);                      // char 변수 1개 출력하는 예제
// printf("%s", var);                    // 문자열 1개 출력하는 예제
// printf("%lld", AB);                   // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <math.h>

#pragma warning(disable:4996) // 제출할때는 지워야함

void run(int x, int y);
void runForward(int x);
void runBackward(int x);

int rotate_num; // 돌리는 횟수
int magnet[4][8]; // 자석의 N,S 극
int rotate[20][2]; // 돌리는 자석과 방향
int pivot[4][2];
int rotate_case[4];
int point[4];

int main(void)
{
	int test_case;
	int T;
	/* 아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	freopen 함수를 이용하면 이후 scanf 를 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	freopen("input.txt", "r", stdin);
	/* 아래 코드를 수행하지 않으면 여러분의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	출력한 내용이 실제 표준 출력에 기록되지 않을 수 있습니다.
	따라서 안전을 위해 반드시 setbuf(stdout, NULL); 을 수행하시기 바랍니다.
	*/
	setbuf(stdout, NULL);
	scanf("%d", &T);
	/*
	여러 개의 테스트 케이스를 처리하기 위한 부분입니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &rotate_num);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				scanf("%d", &magnet[i][j]);
			}
		}
		
		for (int i = 0; i < rotate_num; i++) {
			int magnet_num;
			scanf("%d %d", &magnet_num, &rotate[i][1]);
			rotate[i][0] = magnet_num - 1;
		}

		for (int i = 0; i < 4; i++) {
			pivot[i][0] = 6;
			pivot[i][1] = 2;
			point[i] = 0;
		}

		for (int i = 0; i < rotate_num; i++) {
			int magnet_num = rotate[i][0];
			int direction = rotate[i][1];

			for (int j = 0; j < 4; j++) {
				rotate_case[j] = 0;
			}
			rotate_case[magnet_num] = 1;

			run(magnet_num, direction);
		}
		int answer = 0;
		
		for (int i = 0; i < 4; i++) {
			if (magnet[i][point[i]] == 1) {
				answer += (int)pow((double)2,(double)i);
			}
		}
		printf("#%d %d", test_case, answer);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}

void run(int magnet_num, int direction) {
	if (magnet_num != 0) {
		if (magnet[magnet_num][pivot[magnet_num][0]] != magnet[magnet_num - 1][pivot[magnet_num -1][1]]) {
			if (rotate_case[magnet_num - 1] == 0) {
				rotate_case[magnet_num - 1] = 1;

				run(magnet_num - 1, -direction);
			}
		}
	}
	if (magnet_num != 3) {
		if (magnet[magnet_num][pivot[magnet_num][1]] != magnet[magnet_num + 1][pivot[magnet_num+1][0]]) {
			if (rotate_case[magnet_num + 1] == 0) {
				rotate_case[magnet_num + 1] = 1;
				
				run(magnet_num + 1, -direction);					
			}
		}
	}
	if (direction == 1) { runForward(magnet_num); }
	else { runBackward(magnet_num); }
}

void runForward(int magnet_num) {
	int x = pivot[magnet_num][0];
	int y = pivot[magnet_num][1];
	int p = point[magnet_num];

	if (x > 0) { pivot[magnet_num][0] = x - 1; }
	else { pivot[magnet_num][0] = 7; }

	if (y > 0) { pivot[magnet_num][1] = y - 1; }
	else { pivot[magnet_num][1] = 7; }

	if (p > 0) { point[magnet_num] = p - 1; }
	else { point[magnet_num] = 7; }
}

void runBackward(int magnet_num) {
	int x = pivot[magnet_num][0];
	int y = pivot[magnet_num][1];
	int p = point[magnet_num];

	if (x < 7) { pivot[magnet_num][0] = x + 1; }
	else { pivot[magnet_num][0] = 0; }
	
	if (y < 7) { pivot[magnet_num][1] = y + 1; }
	else { pivot[magnet_num][1] = 0; }

	if (p < 7) { point[magnet_num] = p + 1; }
	else { point[magnet_num] = 0; }
}