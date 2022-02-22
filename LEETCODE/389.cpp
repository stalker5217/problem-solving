#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<char> ss(s.begin(), s.end());
        vector<char> tt(t.begin(), t.end());
        
        sort(ss.begin(), ss.end());
        sort(tt.begin(), tt.end());
        
        int diffIndex = tt.size() - 1;
        for(int i = 0 ; i < ss.size() ; i++) {
            if(ss[i] != tt[i]) {
                diffIndex = i;
                break;
            }
        }
        
        return tt[diffIndex];
    }
};