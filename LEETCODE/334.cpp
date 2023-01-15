#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX;
		int b = INT_MAX;

		for (int num : nums) {
			if (num > b) {
				return true;
			} else if (num > a) {
				b = min(num, b);
			} else if (num <= a) {
				a = num;
			}
		}

		return false;
    }
};