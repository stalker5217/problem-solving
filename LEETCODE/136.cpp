#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> numSet;
        for(int num : nums){
            if(numSet.find(num) != numSet.end()) numSet.erase(num);
            else numSet.insert(num);
        }
        
        return *numSet.begin();
    }
};