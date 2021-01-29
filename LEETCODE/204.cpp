#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        
        int cnt = 0;
        for(long long i = 2 ; i < n ; i++){
            if(isPrime[i]){
                cnt++;
                for(long long j = i * i ; j < n ; j += i){
                    isPrime[j] = false;
                }
            }
        }
        
        return cnt;
    }
};