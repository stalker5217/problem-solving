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
	vector<int> testSite;
	for(int i = 0 ; i < N ; i++){
		int temp;
		cin >> temp;
		testSite.push_back(temp);
	}

	int mainSup;
	int subSup;
	cin >> mainSup >> subSup;

	long long totalSup = 0;
	for(int i = 0 ; i < N ; i++){
		int temp = testSite[i];
		
		// 총감독관
		totalSup++;
		temp -= mainSup;
		if(temp <= 0){
			continue;
		}

		int div = temp / subSup;
		int rem = temp % subSup;

		totalSup += div;
		if(rem > 0){
			totalSup++;
		}
	}
    
	cout << totalSup;

    return 0;
}
