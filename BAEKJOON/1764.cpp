#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, pair<bool, bool> > person;
	int n, m;
	cin >> n >> m;
	// 듣도 못한 사람
	for(int i = 0 ; i < n ; i++){
		string name;
		cin >> name;
		person[name].first = true;
	}
	// 보도 못한 사람
	for(int i = 0 ; i < m ; i++){
		string name;
		cin >> name;
		person[name].second = true;
	}

	vector<string> result;
	unordered_map<string, pair<bool, bool> >::iterator iter;
    for(iter = person.begin() ; iter != person.end() ; iter++){
		// cout << iter->first << " " << iter->second.first << " " << iter->second.second << endl;
		if(iter->second.first == true && iter->second.second == true){
			result.push_back(iter->first);
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for(int i = 0 ; i < result.size() ; i++){
		cout << result[i] << "\n";
	}
    return 0;
}
