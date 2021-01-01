#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> require(n, 0);
	for(int i = 0 ; i < n ; i++){
		cin >> require[i];
	}

	int budget;
	cin >> budget;

	sort(require.begin(), require.end());
	
	vector<int> partialSum(n, 0);
	partialSum[0] = require[0];
	for(int i = 1 ; i < require.size() ; i++){
		partialSum[i] = partialSum[i-1] + require[i];
	}

	int low = 0, high = require[require.size() - 1];
	int answer = 0;
	while(low <= high){
		int mid = (low + high) / 2;
		int idx = upper_bound(require.begin(), require.end(), mid) - require.begin();
		
		int sum = 0;
		sum += (idx > 0) ? partialSum[idx-1] : 0;
		sum += (mid * (require.size() - idx));
		if(sum <= budget){
			answer = mid;
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}

	cout << answer;

    return 0;
}