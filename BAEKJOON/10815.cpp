#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	unordered_set<int> set;

	int n; cin >> n;
	while(n--) {
		int tmp; cin >> tmp;
		set.insert(tmp);
	}

	int m; cin >> m;
	while(m--) {
		int tmp; cin >> tmp;
		if(set.find(tmp) == set.end()) cout << "0 ";
		else cout << "1 ";
	}

    return 0;
}