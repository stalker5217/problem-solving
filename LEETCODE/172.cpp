class Solution {
public:
    int trailingZeroes(int n) {
        int fiveCnt = 0;
        for(int i = 5 ; i <= n ; i *= 5) fiveCnt += (n / i);
        
        return fiveCnt;
    }
};