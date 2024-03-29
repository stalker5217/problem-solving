#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for(int i = 0 ; i < 32 ; i++) if(n & (1 << (31 - i))) ret |= (1 << i);
           
        return ret;
    }
};