#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> & nums, int target) {
        int front = 0;
        int rear = nums.size() - 1;
        
        while(front <= rear){
            int sum = nums[front] + nums[rear];
            
            if(sum == target) break;
            else if(sum < target) front++;
            else rear--;
        }
        
        vector<int> ret = {front+1, rear+1};
		return ret;
    }
};