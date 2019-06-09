#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int N; // 식재료 수
int power[16][16];
vector<int> stack;
int mymin;

void combination(vector<int> food, int offset, int length, int k) {
	if (k == 0) {
		        /*for (int i = 0; i < stack.size(); i++)
				            cout << stack[i] << " ";
							        cout << endl;*/
		vector<int> firstFood, secondFood;

		for (int i = 0; i < N; i++) {
			if (find(stack.begin(), stack.end(), i) != stack.end()) {
				firstFood.push_back(i);
			}
			else {
				secondFood.push_back(i);
			}
		}

		int powerA = 0;
		int powerB = 0;

		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				if (i != j) {
					powerA += power[firstFood[i]][firstFood[j]];
					powerB += power[secondFood[i]][secondFood[j]];
				}
			}
		}

		int val = abs(powerA - powerB);
		if (val < mymin)
			mymin = val;

		return;
	}

	else {
		for (int i = offset; i <= length - k; i++) {
			stack.push_back(food[i]);
			combination(food, i + 1, length, k - 1);
			stack.pop_back();
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
		cin >> N;
		vector<int> food;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> power[i][j];
			}
			food.push_back(i);
		}

		mymin = 10000000000;
		combination(food, 0, food.size(), N / 2);

		cout << "#" << test_case << " " << mymin << endl;
	}
	return 0;
}