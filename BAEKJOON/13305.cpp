#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n;
	cin >> n;

	vector<long long> distance(n-1, 0);
	for(int i = 0 ; i < n - 1 ; i++) cin >> distance[i];

	vector<long long> cost(n, 0);
	for(int i = 0 ; i < n ; i++) cin >> cost[i];

	long long minCost = 1000000000L;
	long long totalCost = 0;
	for(int i = 0 ; i < n - 1; i++) {
		minCost = min(minCost, cost[i]);
		totalCost += distance[i] * minCost;
	}

	cout << totalCost;

    return 0;
}