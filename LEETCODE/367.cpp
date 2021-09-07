class Solution {
public:
    bool isPerfectSquare(int num) {
        bool result = false;
        for(long long i = 1 ; i * i <= num ; i++) {
            if(i * i == num) {
                result = true;
                break;
            }
        }
        
        return result;
    }
};