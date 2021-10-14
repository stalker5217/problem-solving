#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](auto num1, auto num2) {
            string sn1 = to_string(num1);
            string sn2 = to_string(num2);
            
            return (sn1 + sn2) > (sn2 + sn1);
        });
        
        if(nums[0] == 0) return "0";
          
        string answer = "";
        for(auto cur : nums) answer += to_string(cur);
        
        return answer;
    }
};