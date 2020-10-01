#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> preOrder;

void printPostOrder(const int &, const int &);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int temp;
    while(cin >> temp){
		preOrder.push_back(temp);
	}
	
	printPostOrder(0, preOrder.size());

    return 0;
}

void printPostOrder(const int & start, const int & end){
	if(start >= end) return;

	int baseIdx = upper_bound(preOrder.begin() + start + 1, preOrder.begin() + end, preOrder[start]) - preOrder.begin();

	printPostOrder(start + 1, baseIdx);
	printPostOrder(baseIdx, end);
	cout << preOrder[start] << "\n";
}