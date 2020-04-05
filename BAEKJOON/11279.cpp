#define DEBUG 0
#define LOG(string) cout << string

#define CMD 0

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> pq;
	int n;
	cin >> n;

	for(int i = 0 ; i < n ; i++){
		int num;
		cin >> num;
		if(num == CMD){
			if(pq.empty()) cout << "0\n";
			else{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else{
			pq.push(num);
		}
	}
    
    return 0;
}
