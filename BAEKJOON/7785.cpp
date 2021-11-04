#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	unordered_set<string> eSet;
	while(n--) {
		string name; 
		string action;
		cin >> name >> action;

		if(action == "enter") eSet.insert(name);
		else eSet.erase(name);
	}

	vector<string> result;
	for(auto cur : eSet) {
		result.push_back(cur);
	}

	sort(result.begin(), result.end(), [](auto a, auto b) {
		return a > b;
	});

	for(auto cur : result) {
		cout << cur << "\n";
	}

	return 0;
}