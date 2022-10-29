#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int poppedIndex = 0;

        for(int cur : pushed) {
            st.push(cur);
            
            while(!st.empty() && st.top() == popped[poppedIndex]) {
                st.pop();
                poppedIndex++;
            }
        }
        
        return st.empty();
    }
};