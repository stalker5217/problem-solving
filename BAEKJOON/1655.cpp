#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
	cin >> n;

	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	while(n--){
		int cur;
		cin >> cur;

		if(maxHeap.size() > minHeap.size()){
			minHeap.push(cur);
		}
		else{
			maxHeap.push(cur);
		}

		if(!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()){
			int a = maxHeap.top();
			int b = minHeap.top();

			maxHeap.pop();
			minHeap.pop();

			maxHeap.push(b);
			minHeap.push(a);
		}

		cout << maxHeap.top() << "\n";
	}

    return 0;
}