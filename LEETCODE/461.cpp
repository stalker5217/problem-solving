class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;
        int temp = x ^ y;
        while(temp > 0) {
            if(temp & 1 == 1) distance++;
            temp >>= 1;
        }
        
        return distance;
    }
};