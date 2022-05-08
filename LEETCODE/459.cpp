#include <string>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int window = 1 ; window <= s.size() / 2 ; window++) {
            if (s.size() % window > 0) continue;
            
            string base = s.substr(0, window);
            bool valid = true;
            for (int i = window ; i + window <= s.size() ; i += window) {
                if (base != s.substr(i, window)) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) return true;
        }
        
        return false;
    }
};