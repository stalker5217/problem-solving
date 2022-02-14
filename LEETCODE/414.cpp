#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        sort(nums.begin(), nums.end(), [](int a, int b) -> bool {return a > b;});
        
        if(nums.size() >= 3) return nums[2];
        else return nums[0];
    }
};