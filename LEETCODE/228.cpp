#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> answer;
        if(nums.size() == 0) return answer;
        
        int start = nums[0];
        int end = nums[0];
        for(int i = 1 ; i < nums.size() ; i++) {
            if(end + 1 == nums[i]) {
                end = nums[i];
                continue;
            }
            
            if(start == end) answer.push_back(to_string(end));
            else answer.push_back(to_string(start) + "->" + to_string(end));
            
            start = nums[i];
            end = nums[i];
        }
        
        if(start == end) answer.push_back(to_string(end));
        else answer.push_back(to_string(start) + "->" + to_string(end));
        
        return answer;
    }
};