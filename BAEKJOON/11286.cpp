#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

struct compare{
	bool operator()(const int & a, const int & b){
		if(abs(a) > abs(b)) return true;
		else if(abs(a) < abs(b)) return false;
		else if(a > b) return true;
		else if(a < b) return false;
		else return false;
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, compare> pq;
	int cmdCnt;
	cin >> cmdCnt;

	for(int i = 0 ; i < cmdCnt ; i++){
		int val;
		cin >> val;

		if(val == 0){
			if(pq.empty()) cout << "0\n";
			else{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else{
			pq.push(val);
		}
	}
    
    return 0;
}
