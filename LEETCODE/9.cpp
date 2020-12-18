#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
		if(x < 0) return false;

		vector<int> arr;
		for(;x;x/=10){
			arr.push_back(x%10);
		}

		bool ret = true;
		for(int start = 0, end = arr.size() - 1 ; start < end ; start++, end--){
			if(arr[start] != arr[end]){
				ret = false;
				break;
			}
		}

		return ret;
    }
};