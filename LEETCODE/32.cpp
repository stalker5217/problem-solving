#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> st;
        
        st.push(-1);
        for(int i = 0 ; i < s.size() ; i++){
            // CASE LEFT
            if(s[i] == '(') st.push(i);
            // CASE RIGHT
            else{
                st.pop();
                if(st.empty()) st.push(i);
                else maxLen = maxLen > (i - st.top()) ? maxLen : (i - st.top());
            }
        }
         
        return maxLen;
    }
};