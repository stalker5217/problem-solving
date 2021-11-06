#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin >> n;
	vector<int> ropes(n);
	for(int i = 0 ; i < n ; i++) cin >> ropes[i];
	sort(ropes.begin(), ropes.end(), [](auto a, auto b) {
		return a > b;
	});

	int maxWeight = -1;
	for(int i = 0 ; i < n ; i++) maxWeight = max(maxWeight, (i+1) * ropes[i]);

	cout << maxWeight;

    return 0;
}