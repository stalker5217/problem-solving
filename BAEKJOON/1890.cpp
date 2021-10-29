#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<vector<int> > arr(n, vector<int>(n, 0));

	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++) {
			cin >> arr[i][j];
		}
	}

	vector<vector<long long> > cnt(n, vector<long long>(n, 0));
	cnt[0][0] = 1;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++) {
			if(arr[i][j] == 0) continue;

			if(i + arr[i][j] < n) cnt[i + arr[i][j]][j] += cnt[i][j];
			if(j + arr[i][j] < n) cnt[i][j + arr[i][j]] += cnt[i][j];
		}
	}

	cout << cnt[n-1][n-1];

	return 0;
}