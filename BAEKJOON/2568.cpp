#define DEBUG 0
#define LOG(string) cout << string
#define INF 987654321

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int> > electricWire;
	for(int i = 0 ; i < n ; i++){
		int start, end;
		cin >> start >> end;
		electricWire.push_back({start, end});
	}
	sort(electricWire.begin(), electricWire.end());

	vector<int> lis;
	lis.push_back(-1000000000);
	vector<pair<int, int> > trace;
	int cnt = 0;

	for(int i = 0 ; i < n ; i++){
		if(electricWire[i].second > lis.back()){
			lis.push_back(electricWire[i].second);
			trace.push_back({++cnt, electricWire[i].first});
		}
		else{
			int idx = lower_bound(lis.begin(), lis.end(), electricWire[i].second) - lis.begin();
			lis[idx] = electricWire[i].second;
			trace.push_back({idx, electricWire[i].first});
		}
	}

	int idx = cnt;
	stack<int> removeTarget;
	for(int i = trace.size() - 1 ; i >= 0 ; i--){
		if(trace[i].first == idx) idx--;
		else removeTarget.push(trace[i].second);
	}

	int answer = n - lis.size() + 1;
	cout << answer << "\n";
	while(!removeTarget.empty()){
		cout << removeTarget.top() << "\n";
		removeTarget.pop();
	}

    return 0;
}