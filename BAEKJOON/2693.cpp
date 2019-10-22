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

	int T;
	cin >> T;
	for(int test_case = 1 ; test_case <= T ; test_case++){
		vector<int> mVector;
		for(int i = 0 ; i < 10 ; i++){
			int temp;
			cin >> temp;
			mVector.push_back(temp);
		}
		sort(mVector.begin(), mVector.end(), greater<int>());

		cout << mVector[2] << "\n";
	}

	
    
    
    return 0;
}
