#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int size;
	cin >> size;

	vector<int> arr;
	for(int i = 0 ; i < size ; i++){
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	vector<int> dp;
	dp.push_back(arr[0]);
	for(int i = 1 ; i < arr.size() ; i++){
		if(dp[i-1] + arr[i] > arr[i]){
			dp.push_back(dp[i-1] + arr[i]);
		}
		else{
			dp.push_back(arr[i]);
		}
	}

	int maxVal = -99999999;
	for(int i = 0 ; i < dp.size() ; i++){
		if(maxVal < dp[i]){
			maxVal = dp[i];
		}
	}

	cout << maxVal;
	
    return 0;
}
