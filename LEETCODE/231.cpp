class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        
        n &= (n-1);
		if(n) return false;
		else return true;
    }
};