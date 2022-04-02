#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        
        int answer = -1;
        while(start <= end) {
            int mid = (start + end) / 2;
            
            if (nums[mid] == target) {
                answer = mid;
                break;
            } 
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else if (nums[mid] > target) {
                end = mid - 1;
            }
        }
        
        return answer;
    }
};