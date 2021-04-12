#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int criteria = nums.size() / 2;        
        unordered_map<int, int> numMap;
        for(auto num : nums) numMap[num]++;
        for(auto iter : numMap){
            if(iter.second > criteria) return iter.first;
        }
        
        return 0;
    }
};