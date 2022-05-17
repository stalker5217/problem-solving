#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> answer(nums.size());
        
        stack<pair<int, int> > st;
        st.push({nums[0], 0});
        for(int i = 1 ; i < nums.size() ; i++) {
            while(!st.empty() && st.top().first < nums[i]) {
                answer[st.top().second] = nums[i];
                st.pop();
            }
            
            st.push({nums[i], i});
        }
        
        // for circular
        for(int i = 0 ; i < nums.size() ; i++) {
            while(!st.empty() && st.top().first < nums[i]) {
                answer[st.top().second] = nums[i];
                st.pop();
            }
        }
        
        while(!st.empty()) {
            answer[st.top().second] = -1;
            st.pop();
        }
        
        return answer;
    }
};