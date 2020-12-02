#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> height(n);
	for(int i = 0 ; i < n ; i++){
		cin >> height[i];
	}

	int maxArea = -1;
	stack<int> hStack;
	for(int i = 0 ; i < n ; i++){
		int cur;
		cin >> cur;

		while(!hStack.empty() && height[hStack.top()] > height[i]){
			int idx = hStack.top();
			hStack.pop();
			int curHeight = height[idx];

			int curWidth;
			if(hStack.empty()) curWidth = i;
			else curWidth = i - hStack.top() - 1;
			
			maxArea = max(maxArea, curWidth * curHeight);
		}
		hStack.push(i);
	}

	while(!hStack.empty()){
		int idx = hStack.top();
		hStack.pop();
		int curHeight = height[idx];

		int curWidth;
		if(hStack.empty()) curWidth = n;
		else curWidth = n - hStack.top() - 1;
		
		maxArea = max(maxArea, curWidth * curHeight);
	}

	cout << maxArea;
    
    return 0;
}