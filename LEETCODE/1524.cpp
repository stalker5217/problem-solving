#include <vector>

using namespace std;

class Solution {
private:
	const long long mod = 1e9 + 7;
    
public:
	int numOfSubarrays(vector<int>& arr) {
		int even = 0;
		int odd = 0;
		int answer = 0;
		
		for(int i = 0 ; i < arr.size() ; i++) {
			if (arr[i] % 2 == 1) {
				int nextEven = odd;
				odd = even + 1;
				even = nextEven;
			} else {
				even = even + 1;
			}

			answer += odd;
            answer %= mod;
		}

		return answer;
	}
};