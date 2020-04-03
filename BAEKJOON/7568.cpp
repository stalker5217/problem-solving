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

	int n;
	cin >> n;
	vector<pair<int, int> > personArr;
	for(int i = 0 ; i < n ; i++){
		pair<int,int> p;
		cin >> p.first >> p.second;
		personArr.push_back(p);
	}

	for(int i = 0 ; i < n ; i++){
		int rank = 1;
		for(int j = 0 ; j < n ; j++){
			if(personArr[j].first > personArr[i].first && personArr[j].second > personArr[i].second){
				rank++;
			}
		}
		cout << rank << " ";
	}
 
    return 0;
}
