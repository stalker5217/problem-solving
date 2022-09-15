#include <string>
#include <stack> 

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st_s, st_t;
        
        for(char cur : s) {
            if (cur == '#') {
                if (!st_s.empty()) {
                    st_s.pop();
                }
            } else {
                st_s.push(cur);
            }
        }
        
        for(char cur : t) {
            if (cur == '#') {
                if (!st_t.empty()) {
                    st_t.pop();
                }
            } else {
                st_t.push(cur);
            }
        }
        
        return st_s == st_t;
    }
};