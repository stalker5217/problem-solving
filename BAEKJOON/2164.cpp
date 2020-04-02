#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<int, int> cardCnt;
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		int num;
		cin >> num;
		cardCnt[num]++;
	}

	int m;
	cin >> m;
	for(int i = 0 ; i < m ; i++){
		int num;
		cin >> num;
		cout << cardCnt[num];
		if(i < m - 1){
			cout << " ";
		}
	}
    
    return 0;
}
