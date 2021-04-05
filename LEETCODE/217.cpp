#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;
        for(auto num : nums){
            if(numSet.find(num) == numSet.end()) numSet.insert(num);
            else return true;
        }
        
        return false;
    }
};