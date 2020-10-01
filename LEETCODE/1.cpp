#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> & nums, int target) {
        vector<int> ret;
		
		for(int i = 0 ; i < nums.size() - 1 ; i++){
			for(int j = 0 ; j < nums.size() ; j++){
				int sum = nums[i] + nums[j];
				if(sum == target && i != j){
					ret.push_back(i);
					ret.push_back(j);
					return ret;
				}
			}
		}

		return ret;
    }
};