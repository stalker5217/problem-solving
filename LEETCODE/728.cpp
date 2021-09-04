#include <vector>

using namespace std;

class Solution {
private:
    bool inspectSelfDividing(int num) {
        int dividend = num;
        bool isSelfDividing = true;
        
        while(num > 0) {
            int divisor = num % 10;
            if(divisor == 0 || dividend % divisor != 0) {
                isSelfDividing = false;
                break;
            }
            
            num /= 10;
        }
        
        return isSelfDividing;
    }
    
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int i = left ; i <= right ; i++) {
            if(inspectSelfDividing(i)) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};