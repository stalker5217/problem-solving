#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;



int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M; // 지도 크기 및 집당 페이
		cin >> N >> M;

		vector<pair<int, int>> home;


		// 집 위치 기록
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int temp;
				cin >> temp;
				if (temp > 0) {
					home.push_back(make_pair(i, j));
				}
			}
		}

		int max_K = 1;
		int maxPay = home.size() * M;
		while (true) {
			int cost = max_K * max_K + (max_K - 1) * (max_K - 1);
			if (cost > maxPay)
				break;
			else
				max_K++;
		}

		int canService;
		int maxService = -1;
		for (int k = 1; k < max_K; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					canService = 0;
					for (int h = 0; h < home.size(); h++) {
						int lenx = abs(home[h].first - i);
						int leny = abs(home[h].second - j);
						if (lenx + leny <= k - 1) {
							canService++;
						}
					}
					int cost;
					cost = k * k + (k - 1)*(k - 1);
					if (cost <= canService * M && maxService < canService) {
						maxService = canService;
					}
				}
			}
		}

		cout << "#" << test_case << " " << maxService << endl;
	}
	return 0;
}