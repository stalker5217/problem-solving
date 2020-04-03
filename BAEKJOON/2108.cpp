#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
	cin >> n;

	int sum = 0;
	unordered_map<int, int> numCnt;
	vector<int> arr;
	for(int i = 0 ; i < n ; i++){
		int temp;
		cin >> temp;

		sum += temp;
		arr.push_back(temp);
		numCnt[temp]++;
	}
	sort(arr.begin(), arr.end());
	
	// 1. 산술평균(반올림)
	int avg = floor(((double)sum / arr.size()) + 0.5);

	// 2. 중앙 값
	int mid = arr[arr.size() / 2];

	// 3. 최빈 값(여러 개면 두 번째로 작은 값)
	vector<int> mostCntArr;
	int maxCnt = 0;
	for(unordered_map<int,int>::iterator iter = numCnt.begin() ; iter != numCnt.end() ; iter++){
		if(iter->second > maxCnt){
			maxCnt = iter->second;
			mostCntArr.clear();
			mostCntArr.push_back(iter->first);
		}
		else if(iter->second == maxCnt){
			mostCntArr.push_back(iter->first);
		}
	}
	int mostFre;
	if(mostCntArr.size() == 1){
		mostFre = mostCntArr[0];
	}
	else{
		sort(mostCntArr.begin(), mostCntArr.end());
		mostFre = mostCntArr[1];
	}

	// 4. 범위
	int range = arr[arr.size() - 1] - arr[0];
	
	cout << avg << "\n";
	cout << mid << "\n";
	cout << mostFre << "\n";
	cout << range << "\n";
    
    return 0;
}
