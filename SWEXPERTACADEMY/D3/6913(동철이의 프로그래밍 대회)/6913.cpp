#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;


	for (int test_case = 1; test_case <= T; ++test_case) {
		int N, M;
		cin >> N >> M;

		vector<int> participant;
		
		for (int i = 0; i < N; i++) {
			participant.push_back(0);
			for (int j = 0; j < M; ++j) {
				int isSolving;
				cin >> isSolving;
				if (isSolving == 1) {
					participant[i]++;
				}
			}
		}

		sort(participant.begin(), participant.end());
		int max = participant[participant.size() - 1];

		int cnt = 0;
		for (int i = 0; i < participant.size(); ++i) {
			if (participant[i] == max)
				cnt++;
		}
		cout << "#" << test_case << " " << cnt << "\n";
	}

	return 0;
}