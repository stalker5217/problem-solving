#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, m;
	cin >> n >> m;

	function<pair<int, int> (int)> getCnt = [](int num) {
		int twoCnt = 0;
		for(long long i = 2 ; i <= num ; i *= 2) twoCnt += num / i;
		
		int fiveCnt = 0; 
		for(long long i = 5 ; i <= num ; i *= 5) fiveCnt += num / i;
		
		return make_pair(twoCnt, fiveCnt);
	};

	auto nCnt = getCnt(n);
	auto mCnt = getCnt(m);
	auto nmCnt = getCnt(n - m);
	
	pair<int, int> result = {nCnt.first - mCnt.first - nmCnt.first, nCnt.second - mCnt.second - nmCnt.second};
	int answer = min(result.first, result.second);
	
	cout << answer;

	return 0;
}