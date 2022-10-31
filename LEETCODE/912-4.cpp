#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    /**
     * Heap Sort
     */
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int num : nums) {
            pq.push(num);
        }
        
        for(int i = 0 ; i < nums.size() ; i++) {
            nums[i] = pq.top();
            pq.pop();
        }
        
        return nums;
    }
};