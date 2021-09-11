#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int groundCnt, queryCnt;
	cin >> groundCnt >> queryCnt;

	vector<int> ground(groundCnt + 1, 0);
	for(int i = 1 ; i <= groundCnt ; i++) cin >> ground[i];
	
	vector<int> query(groundCnt + 1, 0);
	while(queryCnt--) {
		int start, end, quantity;
		cin >> start >> end >> quantity;

		query[start] += quantity;
		if(end != groundCnt) query[end + 1] += -quantity;
	}

	for(int i = 1 ; i <= groundCnt ; i++) {
		// 누적합
		query[i] += query[i-1]; 

		ground[i] += query[i];
		cout << ground[i] << " ";
	}

    return 0;
}
