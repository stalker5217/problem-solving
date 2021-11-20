#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int l, c;
	cin >> l >> c;

	vector<char> charList(c, 0);
	for(int i = 0 ; i < c ; i++) cin >> charList[i];
	sort(charList.begin(), charList.end());
	
	unordered_set<char> vowelSet;
	vowelSet.insert('a'); 
	vowelSet.insert('e'); 
	vowelSet.insert('i'); 
	vowelSet.insert('o'); 
	vowelSet.insert('u');

	function<void (vector<char> &, pair<int, int> &, const int, const int)> combination = [&](vector<char> & choice, pair<int, int> & cnt, const int k, const int curPos) {
		if(k == 0) {
			if(cnt.first >= 1 && cnt.second >= 2) {
				for(auto cur : choice) cout << cur;
				cout << "\n";
			}
			
			return;
		}

		for(int i = curPos ; i <= charList.size() - k ; i++) {
			bool isVowel = vowelSet.find(charList[i]) != vowelSet.end();
			
			if(isVowel) cnt.first++;
			else cnt.second++;
			choice.push_back(charList[i]);
			
			combination(choice, cnt, k - 1, i + 1);
			
			choice.pop_back();
			if(isVowel) cnt.first--;
			else cnt.second--;
		}
	};

	vector<char> choice;
	pair<int, int> cnt = {0, 0}; // 모음, 자음
	combination(choice, cnt, l, 0);

	return 0;
}