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

    // Algorithm
    int N;
	cin >> N;

	vector<int> mVector;
	for(int i = 0 ; i < N ; i++){
		int temp;
		cin >> temp;
		mVector.push_back(temp);
	}

	sort(mVector.begin(), mVector.end());

	int sum = 0;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j <= i ; j++){
			sum += mVector[j];
		}
	}

	cout << sum;
    
    return 0;
}
