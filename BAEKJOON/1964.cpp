#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

    vector<long long> pointCnt;
	pointCnt.push_back(5);

	for(int i = 1 ; i < n ; i++){
		pointCnt.push_back((pointCnt[i-1] + 3 * (i+2) - 2) % 45678);
	}
	
	cout << pointCnt[n-1];
    
    return 0;
}
