#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 && nums2.size() == 0) return 0;
		
		vector<int> mergedArray;

		for(int i = 0, j = 0 ; ; ){
			if(i < nums1.size() && j < nums2.size()){
				if(nums1[i] < nums2[j]) mergedArray.push_back(nums1[i++]);
				else mergedArray.push_back(nums2[j++]);
			}
			else if(i < nums1.size()) mergedArray.push_back(nums1[i++]);
			else if(j < nums2.size()) mergedArray.push_back(nums2[j++]);
			else break;
		}

		if(mergedArray.size() % 2) return (double) mergedArray[mergedArray.size() / 2];
		else{
			int mid = mergedArray.size() / 2;
			return (mergedArray[mid] + mergedArray[mid - 1]) / 2.0;
		}
    }
};