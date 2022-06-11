#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int start = 0, end = 0;
        int sum = 0;
        int answer = 100001;
        while(end < nums.size()) {
            sum += nums[end++];
            
            while(start < end && sum > totalSum - x) {
                sum -= nums[start++];
            }
            
            if (totalSum - sum == x) {
                int cur = nums.size() + start - end;
                answer = min(answer, cur);
            }
        }
        
        return (answer == 100001) ? -1 : answer;
    }
};