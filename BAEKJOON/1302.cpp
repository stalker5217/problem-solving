#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	unordered_map<string, int> sellMap;
	for(int i = 0 ; i < n ; i++) {
		string s; cin >> s;

		if(sellMap.find(s) == sellMap.end()) sellMap[s] = 1;
		else sellMap[s] += 1;
	}

	string bestSeller = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	int cnt = 0;
	for(auto book : sellMap) {
		if(book.second > cnt) {
			bestSeller = book.first;
			cnt = book.second;
		}
		else if(book.second == cnt && bestSeller > book.first) {
			bestSeller = book.first;
		}
	}

	cout << bestSeller;

	return 0;
}