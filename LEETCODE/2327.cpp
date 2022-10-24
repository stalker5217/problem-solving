#include <vector>

using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1'000'000'007;
        vector<long long> dp(n, 0);

        dp[0] = 1;
        for(int i = 0 ; i < n ; i++) {
            for(int j = i + delay ; j < i + forget && j < n ; j++) {
                dp[j] += dp[i];
                dp[j] %= MOD;
            }
        }

        long long answer = 0;
        for(int i = n - forget ; i < n ; i++) {
            answer += dp[i];
            answer %= MOD;
        }

        return answer;
    }
};