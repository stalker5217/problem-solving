#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; 
	cin >> n >> k;

	vector<int> powerbar;
	vector<int> schedule(k);
	for(int i = 0 ; i < k ; i++) cin >> schedule[i];

	int outCnt = 0 ;
	for(int i = 0 ; i < schedule.size() ; i++) {
		// 이미 꽂혀있는 경우에는 PASS
		bool isPluggedIn = find(powerbar.begin(), powerbar.end(), schedule[i]) != powerbar.end();
		if(isPluggedIn) continue;

		// 멀티탭에 자리가 남아있는 경우 
		if(powerbar.size() < n) {
			powerbar.push_back(schedule[i]);
			continue;
		}

		outCnt++;
		// 가장 오래 사용되지 않을 놈을 제거
		int maxUsePlan = -1;
		int maxUsePlanIndex = -1;
		for(int p = 0 ; p < powerbar.size() ; p++) {
			int usePlan = find(schedule.begin() + i, schedule.end(), powerbar[p]) - schedule.begin();
			if(usePlan > maxUsePlan) {
				maxUsePlan = usePlan;
				maxUsePlanIndex = p;
			}
		}
		powerbar.erase(powerbar.begin() + maxUsePlanIndex);
		powerbar.push_back(schedule[i]);
	}
	
	cout << outCnt;

	return 0;
}