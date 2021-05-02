#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> result;
        
        int zeroCnt = 0;
        for(auto num : nums){
            if(num == 0) zeroCnt++;
            else result.push_back(num);
        }
        
        vector<int> zeroVector(zeroCnt, 0);
        result.insert(result.end(), zeroVector.begin(), zeroVector.end());
        
        nums = result;
    }
};