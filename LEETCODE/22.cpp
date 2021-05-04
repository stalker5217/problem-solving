#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        helper(ret, "", 0, 0, n);
        
        return ret;
    }
    
    void helper(vector<string> & ret,
                string tmp,
                int openParenthesesSize,
                int closeParenthesesSize,
                const int n){
        if(tmp.size() == 2 * n){
            ret.push_back(tmp);
            return;
        }
        
        if(openParenthesesSize < n){
            tmp.push_back('(');
            helper(ret, tmp, openParenthesesSize + 1, closeParenthesesSize, n);
            tmp.pop_back();
        }
        if(openParenthesesSize > closeParenthesesSize) {
            tmp.push_back(')');    
            helper(ret, tmp, openParenthesesSize, closeParenthesesSize + 1, n);
            tmp.pop_back();
        }
    }
};