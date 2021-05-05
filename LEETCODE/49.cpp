#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > um;
        
        for(auto str : strs){
            string key = str;
            sort(key.begin(), key.end());
            um[key].push_back(str);
        }
        
        vector<vector<string> > ret;
        for(auto el : um) ret.push_back(el.second);
        
        return ret;
    }
};