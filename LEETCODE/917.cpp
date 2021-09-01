#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack<char> mStack;
        vector<bool> isAlphabet;
        for(int i = 0 ; i < s.size() ; i++) {
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
                mStack.push(s[i]);
                isAlphabet.push_back(true);
            }
            else isAlphabet.push_back(false);
        }
        
        string result = "";
        for(int i = 0 ; i < s.size() ; i++) {
            if(isAlphabet[i]) {
                result += mStack.top();
                mStack.pop();
            }
            else result += s[i];
        }
        
        return result;
    }
};