#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        
        int index = 0;
        int carry = 0;
        while(k > 0 || carry > 0) {
            int cur;
            if (index < num.size()) cur = num[index] + (k % 10) + carry;
            else cur = (k % 10) + carry;   

            carry = cur / 10;
            cur %= 10;
            
            if (index < num.size()) num[index] = cur;
            else num.push_back(cur);
            
            index++;
            k /= 10;
        }
        
        if (carry) num.push_back(carry);
        
        reverse(num.begin(), num.end());
        
        return num;
    }
};