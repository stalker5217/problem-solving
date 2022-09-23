#include <vector>

using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<bool> isPrime(20, false);
        isPrime[2] = true;
        isPrime[3] = true;
        isPrime[5] = true;
        isPrime[7] = true;
        isPrime[11] = true;
        isPrime[13] = true;
        isPrime[17] = true;
        isPrime[19] = true;
        
        int primeCnt = 0;
        for (int i = left ; i <= right ; i++) {
            int bitCnt = getBitCount(i);
            if (isPrime[bitCnt]) {
                primeCnt++;
            }
        }
        
        return primeCnt;
    }
    
private:
    int getBitCount(int n) {
        int cnt = 0;
        while (n > 0) { 
            if (n & 1) cnt++;
            n >>= 1;
        }
        
        return cnt;
    }
};