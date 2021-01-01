#define DEBUG 0
#define LOG(string) cout << string
#define INF 987654321

#include <iostream>
#include <vector>
#include <algorithm>

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

	for(int i = 0 ; i < n ; i++){
		int cur = electricWire[i].second;

		if(cur > lis.back()) lis.push_back(cur);
		else{
			int idx = lower_bound(lis.begin(), lis.end(), cur) - lis.begin();
			lis[idx] = cur;
		}
	}

	int answer= n - lis.size() + 1;
	cout << answer;
	
    return 0;
}