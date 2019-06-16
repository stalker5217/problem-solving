#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>

using namespace std;


typedef struct __Person {
	int x, y;
	int first;
	int first_id;
	int second;
	int second_id;
} Person;

typedef struct __AP {
	int id;
	int coverage;
	int power;
	int x;
	int y;
} AP;

void move(Person *p, int dir) {
	switch (dir) {
	case 0:
		break;
	case 1:
		p->y -= 1;
		break;
	case 2:
		p->x += 1;
		break;
	case 3:
		p->y += 1;
		break;
	case 4:
		p->x -= 1;
		break;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int M, A; // 사용자의 이동 횟수, AP의 숫자
		cin >> M >> A;

		Person perA, perB;
		perA.x = 1;
		perA.y = 1;
		perA.first = 0;
		perA.second = 0;
		perA.first_id = -1;
		perA.second_id = -1;

		perB.x = 10;
		perB.y = 10;
		perB.first = 0;
		perB.second = 0;
		perB.first_id = -1;
		perB.second_id = -1;

		int *dirA = new int[M];
		int *dirB = new int[M];

		AP * ap = new AP[A];

		for (int i = 0; i < M; i++)
			cin >> dirA[i];
		for (int i = 0; i < M; i++)
			cin >> dirB[i];
		for (int i = 0; i < A; i++) {
			cin >> ap[i].x >> ap[i].y >> ap[i].coverage >> ap[i].power;
			ap[i].id = i + 1;
		}

		// 값 확인 알고리즘
		int sum = 0;

		for (int i = 0; i <= M; i++) {
			// 검사
			for (int j = 0; j < A; j++) {
				int lenx = abs(ap[j].x - perA.x);
				int leny = abs(ap[j].y - perA.y);

				if (lenx + leny <= ap[j].coverage) {
					if (ap[j].power >= perA.first) {
						perA.second = perA.first;
						perA.second_id = perA.first_id;

						perA.first = ap[j].power;
						perA.first_id = ap[j].id;
					}

					else if (ap[j].power >= perA.second) {
						perA.second = ap[j].power;
						perA.second_id = ap[j].id;
					}
				}

				lenx = abs(ap[j].x - perB.x);
				leny = abs(ap[j].y - perB.y);

				if (lenx + leny <= ap[j].coverage) {

					if (ap[j].power >= perB.first) {
						perB.second = perB.first;
						perB.second_id = perB.first_id;

						perB.first = ap[j].power;
						perB.first_id = ap[j].id;
					}

					else if (ap[j].power >= perB.second) {
						perB.second = ap[j].power;
						perB.second_id = ap[j].id;
					}
				}
			}

			if (perA.first_id != perB.first_id)
				sum += perA.first + perB.first;
			else {
				sum += perA.first;

				if (perA.second > perB.second)
					sum += perA.second;
				else if (perA.second < perB.second)
					sum += perB.second;
				else
					sum += perA.second;
			}

			perA.first = 0;
			perA.first_id = -1;
			perA.second = 0;
			perA.second_id = -1;

			perB.first = 0;
			perB.first_id = -1;
			perB.second = 0;
			perB.second_id = -1;


			if (i == M)
				break;

			// 이동
			move(&perA, dirA[i]);
			move(&perB, dirB[i]);
		}

		cout << "#" << test_case << " " << sum << endl;

		delete[] dirA;
		delete[] dirB;
		delete[] ap;
	}
	return 0;
}