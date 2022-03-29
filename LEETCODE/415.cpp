#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        string answer = "";
        int carry = 0;
        for(int i = 0 ; i < max(num1.size(), num2.size()) ; i++) {
            int a = 0, b = 0;
            if (i < num1.size()) a = num1[i] - '0';
            if (i < num2.size()) b = num2[i] - '0';
            
            int sum = a + b + carry;
            
            if (sum >= 10) {
                answer += to_string(sum - 10);
                carry = 1;
            }
            else {
                answer += to_string(sum);
                carry = 0;
            }
        }
        
        if(carry > 0) answer += to_string(carry);
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};