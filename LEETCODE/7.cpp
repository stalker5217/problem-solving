#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
		long long result = 0;

		for( ; x ; x /= 10){
			result *= 10;
			result += (x%10);
		}

		int answer = 0;
		if(result <= INT_MAX && result >= INT_MIN) answer = result;

		return result;
    }
};

int main(){
	int x = 1534236469;
	Solution s;
	cout << s.reverse(x);

	return 0;
}