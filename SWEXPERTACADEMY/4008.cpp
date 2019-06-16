#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>

using namespace std;

int *num;
int mymax = -1000000001;
int mymin = 1000000001;

void permutation(char* op, int s, int e) {
	if (s == e) {
		int result = num[0];

		for (int i = 0; i <= e; i++) {
			switch (op[i]) {
			case '+':
				result += num[i + 1];
				break;
			case '-':
				result -= num[i + 1];
				break;
			case '*':
				result *= num[i + 1];
				break;
			case '/':
				result /= num[i + 1];
				break;
			}
		}

		if (result > mymax)
			mymax = result;
		if (result < mymin)
			mymin = result;
	}

	else {
		for (int i = s; i <= e; i++) {
			char temp;
			if (op[s] == op[i] && s != i) {
				continue;
			}
			else {
				temp = op[s];
				op[s] = op[i];
				op[i] = temp;
			}

			permutation(op, s + 1, e);

			temp = op[s];
			op[s] = op[i];
			op[i] = temp;
		}
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
		int N;
		cin >> N;

		int op_num[4];
		cin >> op_num[0] >> op_num[1] >> op_num[2] >> op_num[3];

		char *op = new char[N - 1];
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < op_num[i]; j++) {
				switch (i) {
				case 0:
					op[cnt] = '+';
					break;
				case 1:
					op[cnt] = '-';
					break;
				case 2:
					op[cnt] = '*';
					break;
				case 3:
					op[cnt] = '/';
					break;
				}
				cnt++;
			}
		}


		num = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> num[i];
		}

		mymax = -1000000001;
		mymin = 1000000001;

		permutation(op, 0, N - 2);

		delete[] op;
		delete[] num;

		cout << "#" << test_case << " " << mymax - mymin << endl;
	}
	return 0;
}