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

    int n, goal;
	cin >> n >> goal;

	vector<int> arr;
	int maxVal = 0;
	for(int i = 0 ; i < n ; i++){
		int temp;
		cin >> temp;
		if(maxVal < temp){
			maxVal = temp;
		}
		arr.push_back(temp);
	}

	long long start = 1;
	long long mid;
	long long end = maxVal;
	long long answer = start;

	while(true){
		if(start > end){
			break;
		}

		mid = (start + end) / 2;
		long long lansCnt = 0;
		for(int i = 0 ; i < arr.size() ; i++){
			lansCnt += arr[i] / mid;
		}

		if(lansCnt >= goal){
			answer = mid;
			start = mid + 1;
		}
		else{
			end = mid - 1;
		}
	}

	cout << answer;

    return 0;
}
