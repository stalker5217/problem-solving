#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
	
	vector<int> a(n);
	for(int i = 0 ; i < a.size() ; i++) cin >> a[i];
	
	vector<int> b(m);
	for(int i = 0 ; i < b.size() ; i++) cin >> b[i];
	
	vector<int> result;

	int aPointer = 0, bPointer = 0;
	while(aPointer < a.size() && bPointer < b.size()) {
		if(a[aPointer] < b[bPointer]) result.push_back(a[aPointer++]);
		else result.push_back(b[bPointer++]);
	}

	while(aPointer < a.size()) result.push_back(a[aPointer++]);
	while(bPointer < b.size()) result.push_back(b[bPointer++]);

	for(auto cur : result) cout << cur << " ";

    return 0;
}