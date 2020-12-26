#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool needContinue = true;
        for(int i = digits.size() - 1 ; i >= 0 && needContinue ; i--){
            if(digits[i] + 1 == 10){
                needContinue = true;
                digits[i] = 0;
            }
            else{
                needContinue = false;
                digits[i] = digits[i] + 1;
                break;
            }
        }
        
        if(needContinue) digits.insert(digits.begin(), 1);
        return digits;
    }
};