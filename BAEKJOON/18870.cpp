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
	vector<int> origin;
	for(int i = 0 ; i < n ; i++){
		int tmp;
		cin >> tmp;
		origin.push_back(tmp);
	}

	vector<int> v;
	v.assign(origin.begin(), origin.end());
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for(int i = 0 ; i < origin.size() ; i++){
		int cnt = lower_bound(v.begin(), v.end(), origin[i]) - v.begin();
		cout << cnt << " ";
	}
    
    return 0;
}
