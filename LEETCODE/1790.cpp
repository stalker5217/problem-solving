#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int length = s1.size();
        vector<int> diffIndex;
        
        for(int i = 0 ; i < length ; i++) {
            if (s1[i] != s2[i]) diffIndex.push_back(i);
        }
        
        if (diffIndex.size() == 0) return true;
        
        if (diffIndex.size() == 2) {
            int a = diffIndex[0];
            int b = diffIndex[1];

            if (s1[a] == s2[b] && s1[b] == s2[a]) return true;
        } 
        
        return false;
    }
};