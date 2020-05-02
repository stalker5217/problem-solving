#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	cin >> t;
	for(int test_case = 1 ; test_case <= t ; test_case++){
		int n;
		cin >> n;
		unordered_map<string, int> cMap;

		for(int i = 0 ; i < n ; i++){
			string clothes, type;
			cin >> clothes >> type;

			if(cMap.find(type) == cMap.end()) cMap[type] = 2;
			else cMap[type] = cMap[type] + 1;
		}

		int answer = 1;
		for(auto iter = cMap.begin() ; iter != cMap.end() ; iter++){
			answer *= (*iter).second;
		}
		answer--;

		cout << answer << "\n";
	}

    
    return 0;
}
