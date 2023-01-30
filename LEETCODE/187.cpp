#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) {
            vector<string> empty;
            return empty;
        }
        
        unordered_map<string, int> mp;
		for(int i = 0 ; i <= s.size() - 10 ; i++) {
            string cur = s.substr(i, 10);
			mp[cur]++;
        }

		vector<string> answer;
		for (auto iter : mp) {
			if (iter.second > 1) {
				answer.push_back(iter.first);
			}
		}

		return answer;
    }
};