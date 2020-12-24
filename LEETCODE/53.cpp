#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int answer = nums[0];
        int sum = 0;
        for(int cur : nums){
            sum += cur;
            answer = max(answer, sum);
            if(sum < 0) sum = 0;
        }
        
        return answer;
    }
};