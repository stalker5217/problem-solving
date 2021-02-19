#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string answer = "";
        int aLength = a.size();
        int bLength = b.size();
        int longLen = aLength > bLength ? aLength : bLength;
        
        int carry = 0;
        for(int i = 1 ; i <= longLen ; i++){
            int aCur;
            if(aLength >= i) aCur = a[aLength - i] - '0';
            else aCur = 0;
            
            int bCur;
            if(bLength >= i) bCur = b[bLength - i] - '0';
            else bCur = 0;
            
            int sum = aCur + bCur + carry;
            if(sum >= 2){
                sum -= 2;
                carry = 1;
            }
            else carry = 0;
            
            answer = to_string(sum) + answer;
        }
        
        if(carry) answer = to_string(carry) + answer;
        
        return answer;
    }
};