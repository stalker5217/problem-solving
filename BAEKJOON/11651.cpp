#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Algorithm
    int N;
	cin >> N;
	vector<pair<int, int> > mVector;
	for(int i = 0 ; i < N ; i++){
		int a, b;
		cin >> a >> b;
		mVector.push_back(make_pair(a, b));
	}

	sort(mVector.begin(), mVector.end(), compare);

	for(int i = 0 ; i < N ; i++){
		cout << mVector[i].first << " " << mVector[i].second << "\n";
	}
    
    return 0;
}

bool compare(pair<int, int> a, pair<int, int> b){
	if(a.first < b.first)
		return true;
	else if(a.first > b.first)
		return false;
	else{
		if(a.second < b.second){
			return true;
		}
		else{
			return false;
		}
	}
}