#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;

	vector<int> packageCost(m); // 6개 가격
	vector<int> eachCost(m);    // 낱개 가격
	for(int i = 0 ; i < m ; i++) {
		cin >> packageCost[i];
		cin >> eachCost[i];
	}

	int packageMin = *min_element(packageCost.begin(), packageCost.end());
	int eachMin = *min_element(eachCost.begin(), eachCost.end());

	int minPay = 0;
	if(packageMin < 6 * eachMin) {
		minPay += packageMin * (n / 6);
		n %= 6;

		if(packageMin < n * eachMin) minPay += packageMin;
		else minPay += (n * eachMin);
	}
	else minPay = eachMin * n;
	
	cout << minPay;
	
	return 0;
}