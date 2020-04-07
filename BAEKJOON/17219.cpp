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

    int n,m;
	cin >> n >> m;

	unordered_map<string, string> spMap;

	for(int i = 0 ; i < n ; i++){
		string site;
		string password;

		cin >> site >> password;

		spMap[site] = password;
	}

	for(int i = 0 ; i < m ; i++){
		string site;
		cin >> site;
		cout << spMap[site] << "\n";
	}
    
    return 0;
}
