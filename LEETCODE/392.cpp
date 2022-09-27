#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIdx = 0;
        for(int i = 0 ; i < t.size() ; i++) {
            if(s[sIdx] == t[i]) {
                sIdx++;
            }
        }
        
        return s.size() == sIdx;
    }
};