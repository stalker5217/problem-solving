#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> answer(nums.size());
        
        int front = 0, rear = nums.size() - 1;
        int idx = nums.size() - 1;
        while(front <= rear) {
            if (abs(nums[front]) < abs(nums[rear])) {
                answer[idx--] = nums[rear] * nums[rear];
                rear--;
            }
            else {
                answer[idx--] = nums[front] * nums[front];
                front++;
            }
        }
        
        return answer;
    }
};