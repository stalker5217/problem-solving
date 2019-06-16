#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int num;
		int cnt = 0;
		cin >> num;

		int next = num;
		bool *look = new bool[10];
		bool result = false;

		for (int i = 0; i < 10; i++)
			look[i] = false;

		while (true) { // 배수 읽기
			cnt++;

			int temp = next;
			while (true) { // 숫자 하나 분석
				int remain = temp % 10;
				look[remain] = true;

				temp /= 10;
				if (temp == 0)
					break;
			}

			for (int i = 0; i < 10; i++) {
				if (look[i] == false) {
					break;
				}

				if (i == 9)
					result = true;
			}

			if (result == true)
				break;

			next = num * (cnt + 1);
		}


		cout << "#" << test_case << " " << next << endl;
	}
	return 0;
}