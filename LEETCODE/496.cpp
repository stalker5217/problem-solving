#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nextGreater(nums2.size(), -1);
        unordered_map<int, int> indexMap;
        for(int i = 0 ; i < nums2.size() ; i++) {
            indexMap[nums2[i]] = i;
            for(int j = i + 1 ; j < nums2.size() ; j++) {
                if(nums2[i] < nums2[j]) {
                    nextGreater[i] = nums2[j];
                    break;
                }
            }
        }
        
        vector<int> answer(nums1.size());
        for(int i = 0 ; i < nums1.size() ; i++) {
             answer[i] = nextGreater[indexMap[nums1[i]]];
        }
        
        return answer;
    }
};