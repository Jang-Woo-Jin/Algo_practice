/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// scanf("%d", &a);                      // int ���� 1�� �Է¹޴� ����
// scanf("%f %f", &b, &c);               // float ���� 2�� �Է¹޴� ���� 
// scanf("%lf %lf %lf", &d, &e, &f);     // double ���� 3�� �Է¹޴� ����
// scanf("%c", &g);                      // char ���� 1�� �Է¹޴� ����
// scanf("%s", &var);                    // ���ڿ� 1�� �Է¹޴� ����
// scanf("%lld", &AB);                   // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// printf("%d", a);                      // int ���� 1�� ����ϴ� ����
// printf("%f %f", b, c);                // float ���� 2�� ����ϴ� ����
// printf("%lf %lf %lf", d, e, f);       // double ���� 3�� ����ϴ� ����
// printf("%c", g);                      // char ���� 1�� ����ϴ� ����
// printf("%s", var);                    // ���ڿ� 1�� ����ϴ� ����
// printf("%lld", AB);                   // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <math.h>

#pragma warning(disable:4996) // �����Ҷ��� ��������

void run(int x, int y);
void runForward(int x);
void runBackward(int x);

int rotate_num; // ������ Ƚ��
int magnet[4][8]; // �ڼ��� N,S ��
int rotate[20][2]; // ������ �ڼ��� ����
int pivot[4][2];
int rotate_case[4];
int point[4];

int main(void)
{
	int test_case;
	int T;
	/* �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	freopen �Լ��� �̿��ϸ� ���� scanf �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	freopen("input.txt", "r", stdin);
	/* �Ʒ� �ڵ带 �������� ������ �������� ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	����� ������ ���� ǥ�� ��¿� ��ϵ��� ���� �� �ֽ��ϴ�.
	���� ������ ���� �ݵ�� setbuf(stdout, NULL); �� �����Ͻñ� �ٶ��ϴ�.
	*/
	setbuf(stdout, NULL);
	scanf("%d", &T);
	/*
	���� ���� �׽�Ʈ ���̽��� ó���ϱ� ���� �κ��Դϴ�.
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
	return 0; //��������� �ݵ�� 0�� �����ؾ� �մϴ�.
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