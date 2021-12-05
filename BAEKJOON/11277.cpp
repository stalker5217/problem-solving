#include <iostream>
#include <vector>

using namespace std;

bool isTrue(int val, int n) {
	if(n > 0 && ((val >> (n - 1)) & 1)) return true;
	else if(n < 0 && (((val >> (-n - 1)) & 1) == 0)) return true;

	return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<pair<int, int> > clauses;
	for(int i = 0 ; i < m ; i++) {
		int a, b;
		cin >> a >> b;
		clauses.push_back({a, b});
	}

	bool possible;
	for(int i = 0 ; i < (1 << n) ; i++) {
		possible = true;
		
		for(auto clause : clauses) {
			if(!isTrue(i, clause.first) && !isTrue(i, clause.second)) {
				possible = false;
				break;
			}
		}

		if(possible) break;
	}

	if(possible) cout << "1\n";
	else cout << 0; 

    return 0;
}