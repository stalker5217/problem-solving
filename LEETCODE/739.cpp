#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int> > st;
        vector<int> answer(temperatures.size(), 0);
        for(int i = 0 ; i < temperatures.size() ; i++) {
            
            while(!st.empty() && st.top().second < temperatures[i]) {
                auto top = st.top();
                answer[top.first] = i - top.first;
                st.pop();
            }
            
            st.push({i, temperatures[i]});
        }
        
        return answer;
    }
};