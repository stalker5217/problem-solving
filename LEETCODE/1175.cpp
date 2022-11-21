#include <vector>

using namespace std;

class Solution {
public:
    int numPrimeArrangements(int n) {
        vector<bool> prime(n + 1, true);
        prime[1] = false;
        for(int i = 2 ; i * i <= n ; i++) {
            if (prime[i]) {
                for(int j = i * i ; j <= n ; j += i) {
                    prime[j] = false;
                }
            }
        }
        
        int primeCnt = 0;
        for(int i = 1 ; i <= n ; i++) {
            if (prime[i]) {
                primeCnt++;
            }
        }
        
        int nonPrimeCnt = n - primeCnt;
                
        long long answer = 1L;
        const int MOD = 1e9 + 7;
        while(primeCnt) {
            answer *= primeCnt--;
            answer %= MOD;
        }
        
        while(nonPrimeCnt) {
            answer *= nonPrimeCnt--;
            answer %= MOD;
        }
        
        return answer;
    }
};