#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

int mymin;
int dc, mc, tmc, yc; // 1일, 1달, 3달, 1년 가격

void costEval(bool* cover, int* month, int baseCost) {
	int cost = baseCost;
	bool isCover[13];
	memcpy(isCover, cover, sizeof(bool) * 13);


	// 3달권을 더 이상 사용하지 않는 경우.
	for (int i = 1; i <= 12; i++) {
		if (isCover[i] == false && month[i] > 0)
		{
			int dayCost = dc * month[i];
			int monthCost = mc;

			if (dayCost < monthCost)
				cost += dayCost;
			else
				cost += monthCost;
		}
	}

	if (cost < mymin)
		mymin = cost;


	cost = baseCost;
	// 3달권을 추가로 사용해보는  경우.
	for (int i = 1; i <= 10; i++) {
		if (isCover[i] == false && isCover[i + 1] == false && isCover[i + 2] == false) {
			isCover[i] = true;
			isCover[i + 1] = true;
			isCover[i + 2] = true;

			costEval(isCover, month, baseCost + tmc);

			isCover[i] = false;
			isCover[i + 1] = false;
			isCover[i + 2] = false;

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
		cin >> dc >> mc >> tmc >> yc;

		int month[13];

		for (int i = 1; i <= 12; i++) {
			cin >> month[i];
		}

		mymin = yc; // 일단 1년 이용권을 최저로 잡는다.

		bool isCover[13] = { false, };
		costEval(isCover, month, 0);

		cout << "#" << test_case << " " << mymin << endl;
	}
	return 0;
}