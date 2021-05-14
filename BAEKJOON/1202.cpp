#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int jewelryCnt, bagCnt;
	cin >> jewelryCnt >> bagCnt;

	priority_queue<pair<int, int > > pq;
	for(int i = 0 ; i < jewelryCnt ; i++){
		int weight, price;
		cin >> weight >> price;

		pq.push({price, weight});
	}

	multiset<int> bags;
	for(int i = 0 ; i < bagCnt ; i++){
		int capacity;
		cin >> capacity;
		bags.insert(capacity);
	}

	long long sum = 0;
	while(!pq.empty()){
		pair<int, int> cur = pq.top();
		
		int curPrice = cur.first;
		int curWeight = cur.second;
		
		pq.pop();

		auto iter = bags.lower_bound(curWeight);
		if(iter != bags.end()){
			sum += curPrice;
			bags.erase(iter);
		}
	}

	cout << sum;
    
    return 0;
}