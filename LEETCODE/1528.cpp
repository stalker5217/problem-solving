#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<pair<int, char>> indexMap;
		for (int i = 0 ; i < s.size() ; i++) {
			indexMap.push_back({indices[i], s[i]});
		}

		sort(indexMap.begin(), indexMap.end());

		string answer = "";
		for (auto cur : indexMap) {
			answer += cur.second;
		}

		return answer;
    }
};