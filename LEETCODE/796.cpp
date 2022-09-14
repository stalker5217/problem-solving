#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        
        if (s.size() == 1) {
            return s == goal;
        }
        
        int rotate = s.size();
        while(rotate--) {
            if (s == goal) {
                return true;
            }
            
            
            string next = s.substr(1, s.size() - 1);
            next += s[0];
            s = next;
        }
        
        return false;
    }
};