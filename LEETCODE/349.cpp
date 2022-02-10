#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> ret;
        for(int e : set1) {
            if(set2.find(e) != set2.end()) ret.push_back(e);
        }
        
        return ret;
    }
};