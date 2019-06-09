#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

enum {
	mPlus = 0, mMinus, mMultiple, mDivide
};

int main() {
	freopen("input.txt", "r", stdin);

	int operandNum;
	vector<int> operandList;
	vector<int> operatorList;
	long long myMin =  1000000000;
	long long myMax = -1000000000;

	cin >> operandNum;

	for (int i = 0; i < operandNum; ++i) {
		int temp;
		cin >> temp;
		operandList.push_back(temp);
	}

	for (int i = 0; i < 4; i++) {
		int cnt;
		cin >> cnt;
		for (int a = 0; a < cnt; a++) {
			operatorList.push_back(i);
		}
	}

	sort(operatorList.begin(), operatorList.end());

	do {
		int result = operandList[0];
		for (int i = 0; i < operatorList.size(); i++) {
			if (operatorList[i] == mPlus) {
				result += operandList[i + 1];
			}

			else if (operatorList[i] == mMinus) {
				result -= operandList[i + 1];
			}

			else if (operatorList[i] == mMultiple) {
				result *= operandList[i + 1];
			}

			else if (operatorList[i] == mDivide) {
				result /= operandList[i + 1];
			}
		}

		if (result > myMax)
			myMax = result;

		if (result < myMin)
			myMin = result;

	} while (next_permutation(operatorList.begin(), operatorList.end()));

	cout << myMax << "\n" << myMin;
}