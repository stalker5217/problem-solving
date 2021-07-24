#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int target;
	cin >> target;

	int n;
	cin >> n;
	vector<int> a(n, 0);
	for(int i = 0 ; i < n ; i++) cin >> a[i];

	int m;
	cin >> m;
	vector<int> b(m, 0);
	for(int i = 0 ; i < m ; i++) cin >> b[i];

	vector<long long> aPartialSum;
	for(int i = 0 ; i < a.size() ; i++) {
		long long sum = 0;
		for(int j = i ; j < a.size() ; j++) {
			sum += a[j];
			aPartialSum.push_back(sum);
		}
	}

	vector<long long> bPartialSum;
	for(int i = 0 ; i < b.size() ; i++) {
		long long sum = 0;
		for(int j = i ; j < b.size() ; j++) {
			sum += b[j];
			bPartialSum.push_back(sum);
		}
	}

	sort(aPartialSum.begin(), aPartialSum.end());
	sort(bPartialSum.begin(), bPartialSum.end(), greater<>());
	int aIndex = 0, bIndex = 0;
	long long answer = 0;
	while(aIndex < aPartialSum.size() && bIndex < bPartialSum.size()) {
		long long sum = aPartialSum[aIndex] + bPartialSum[bIndex];
		if(sum < target) aIndex++;
		else if(sum > target) bIndex++;
		else {
			long long aCnt = 1, bCnt= 1;
			while(aIndex + 1 < aPartialSum.size() && aPartialSum[aIndex] == aPartialSum[aIndex+1]) {aCnt++; aIndex++;}
			while(bIndex + 1 < bPartialSum.size() && bPartialSum[bIndex] == bPartialSum[bIndex+1]) {bCnt++; bIndex++;}

			answer += (aCnt * bCnt);
			aIndex++; bIndex++;
		}
	}

	cout << answer;

    return 0;
}