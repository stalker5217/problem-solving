#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int testCase = 0;
    while(1) {
		int l, p, v;
		cin >> l >> p >> v;

		if(l == 0 && p == 0 && v == 0) break;

		cout << "Case " << ++testCase << ": " << (v / p) * l + min(v % p, l) << "\n";
	}

    return 0;
}