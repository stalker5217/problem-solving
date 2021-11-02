#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	string a, b;
	cin >> a >> b;

	int minDiffCnt = 100;
	for(int i = 0 ; i <= b.size() - a.size() ; i++) {
		int diffCnt = 0;
		for(int j = 0 ; j < a.size() ; j++) {
			if(a[j] != b[i+j]) diffCnt++;
		}
		minDiffCnt = min(minDiffCnt, diffCnt);
	}

	cout << minDiffCnt;

    return 0;
}