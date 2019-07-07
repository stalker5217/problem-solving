#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int cnt;
	cin >> cnt;

	vector<int> arr;

	for(int i = 0 ; i < cnt ; i++){
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	cout << arr[0] * arr[cnt-1];

	return 0;
}