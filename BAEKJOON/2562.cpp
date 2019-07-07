#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
	if(a.first > b.first)
		return true;
	else
		return false;
}

int main(){
	vector<pair<int, int> > arr;

	for(int i = 0 ; i < 9 ; i++){
		int temp;
		cin >> temp;
		arr.push_back(make_pair(temp, i+1));
	}

	sort(arr.begin(), arr.end(), compare);

	cout << arr[0].first << "\n" << arr[0].second;
}