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
    
	int avg;
	int sum = 0;
	vector<int> arr;
	for(int i = 0 ; i < 5 ; i++){
		int temp;
		cin >> temp;
		sum += temp;
		arr.push_back(temp);
	}
	avg = sum / 5;

	sort(arr.begin(), arr.end());

	cout << avg << "\n" << arr[2];

    return 0;
	
}
