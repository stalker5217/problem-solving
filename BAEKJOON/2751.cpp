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
	vector<int> mVector;

	cin >> N;
	for(int i = 0 ; i < N ; i++){
		int temp;
		cin >> temp;
		mVector.push_back(temp);
	}

	sort(mVector.begin(), mVector.end());

	for(int i = 0 ; i < mVector.size() ; i++){
		cout << mVector[i] << "\n";
	}
    
    return 0;
}
