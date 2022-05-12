#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<string> temp;
        int carry = 0;
        for(int index2 = num2.size() - 1 ; index2 >= 0 ; index2--) {
            string cur = "";
            int carry = 0;
            int b = num2[index2] - '0';
            
            for(int index1 = num1.size() - 1 ; index1 >= 0 ; index1--) {
                int a = num1[index1] - '0';
                
                int t = a * b + carry;
                carry = t / 10;
                t %= 10;
                
                cur.push_back(t + '0');
            }
            
            if (carry) cur.push_back(carry + '0');
            reverse(cur.begin(), cur.end());
            
            int pendingZeroCnt = num2.size() - index2 - 1;
            for(int i = 0 ; i < pendingZeroCnt ; i++) cur.push_back('0');
            
            temp.push_back(cur);
        }
        
        string answer = "0";
        for(string cur : temp) {
            answer = add(answer, cur);
        }
        
        for(int i = 0 ; i < answer.size() ; i++) {
            if (answer[i] != '0') return answer.substr(i);
        }
        
        return "0";
    }

private:
    string add(string num1, string num2) {
        string result = "";
        int index1 = num1.size() - 1;
        int index2 = num2.size() - 1;
        int carry = 0;
        while(index1 >= 0 || index2 >= 0) {
            int cur = carry;
            
            if (index1 >= 0) cur += num1[index1--] - '0';
            if( index2 >= 0) cur += num2[index2--] - '0';
            
            carry = cur / 10;
            cur %= 10;

            result.push_back(cur + '0');
        }
        
        if (carry) result.push_back(carry + '0');
        
        reverse(result.begin(), result.end());
        return result;
    }
};