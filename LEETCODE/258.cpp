class Solution {
public:
    int addDigits(int num) {
        int result = num;
        
        while(result >= 10) {
            int target = result;
            result = 0;
            while(target > 0) {
                result += target % 10;
                target /= 10;
            }    
        }
        
        
        return result;
    }
};