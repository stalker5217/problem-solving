#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> answer;
        
        deque<pair<int, int>> d;
        for(int i = 0 ; i < nums.size() ; i++) {
            while(!d.empty() && d.front().first <= i - k) {
                d.pop_front();
            }
            
            while(!d.empty() && d.back().second < nums[i]) {
                d.pop_back();
            }
            
            d.push_back({i, nums[i]});
            
            if (i >= k - 1) {
                answer.push_back(d.front().second);
            }
        }
        
        return answer;
    }
};