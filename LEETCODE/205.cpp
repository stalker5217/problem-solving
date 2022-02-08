#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sourceToTarget;
        unordered_map<char, char> targetToSource;
        
        for(int i = 0 ; i < s.size() ; i++) {
            if(sourceToTarget.find(s[i]) == sourceToTarget.end()) {
                sourceToTarget[s[i]] = t[i];
            }
            else if(sourceToTarget[s[i]] != t[i]) return false;
        }
        
        for(int i = 0 ; i < t.size() ; i++) {
            if(targetToSource.find(t[i]) == targetToSource.end()) {
                targetToSource[t[i]] = s[i];
            }
            else if(targetToSource[t[i]] != s[i]) return false;
        }
        
        return true;
    }
};