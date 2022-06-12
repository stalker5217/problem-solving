#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int answer = 0;
        
        int start = 0;
        int end = 0;
        
        unordered_map<int, int> numMap;
        int sum = 0;
        while(end < nums.size()) {
            int rightVal = nums[end++];
            sum += rightVal;
            numMap[rightVal]++;
            
            while(numMap[rightVal] > 1) {
                int leftVal = nums[start++];
                sum -= leftVal;
                numMap[leftVal]--;
            }
            
            answer = max(answer, sum);
        }
        
        return answer;
    }
};