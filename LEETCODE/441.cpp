class Solution {
public:
    int arrangeCoins(int n) {
        for(int i = 1 ; ; i++) {
            n -= i;
            if (n < 0) 
                return i - 1;
        }
        
        return -1;
    }
};