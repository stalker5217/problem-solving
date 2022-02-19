#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> numMap;
        for(int cur : nums2) numMap[cur]++;
        
        vector<int> ret;
        for(int cur : nums1) {
            if(numMap[cur] > 0) {
                ret.push_back(cur);
                numMap[cur]--;
            }
        }
        
        return ret;
    }
};