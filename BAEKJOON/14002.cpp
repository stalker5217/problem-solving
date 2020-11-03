#define DEBUG 0
#define LOG(string) cout << string
#define INF 987654321

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	int cnt = 0;
	vector<int> lis;
	vector<pair<int, int> > lisIdxValPair;
	
	lis.push_back(0);
	for(int i = 0 ; i < n ; i++){
		int cur;
		cin >> cur;

		if(cur > lis.back()){
			lis.push_back(cur);
			lisIdxValPair.push_back({++cnt, cur});
		}
		else{
			int idx = lower_bound(lis.begin(), lis.end(), cur) - lis.begin();
			lis[idx] = cur;
			lisIdxValPair.push_back({idx, cur});
		}
	}

	stack<int> valStack;
	int idx = cnt;
	for(int i = lisIdxValPair.size() - 1 ; i >= 0 ; i--){
		if(lisIdxValPair[i].first == idx){
			valStack.push(lisIdxValPair[i].second);
			idx--;
		}
	}

	cout << cnt << "\n";
	while(!valStack.empty()){
		cout << valStack.top() << " ";
		valStack.pop();
	}

    return 0;
}