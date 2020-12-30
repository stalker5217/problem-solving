#include <string>

using namespace std;

class Solution {
private:
	const long long _INT_MIN = -2147483648;
	const long long _INT_MAX = 2147483647;

public:
    int myAtoi(string s) {
		int idx = 0;
		while(idx < s.size() && s[idx] == ' ') idx++;

		bool isNegative = false;
		if(idx < s.size() && ((s[idx] == '+') || (s[idx] == '-'))){
			isNegative = s[idx++] == '-' ? true : false;
		}

		bool isOverflow = false;
		long long answer = 0;
		while(idx < s.size() && s[idx] >= '0' && s[idx] <= '9'){
			answer *= 10;
			answer += s[idx++] - '0';

			if(isNegative && answer > -_INT_MIN){
				isOverflow = true;
				break;
			}
			else if(answer > _INT_MAX){
				isOverflow = true;
				break;
			}
			
		}

		if(isOverflow && isNegative) return _INT_MIN;
		else if(isOverflow) return _INT_MAX;

		if(isNegative) answer *= -1;
		return answer;
    }
};