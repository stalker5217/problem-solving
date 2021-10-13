#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        
        vector<int> front = {nums.end() - k, nums.end()};
        vector<int> rear = {nums.begin(), nums.begin() + nums.size() - k};
        
        nums.clear();
        nums.insert(nums.end(), front.begin(), front.end());
        nums.insert(nums.end(), rear.begin(), rear.end());
    }
};