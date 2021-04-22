class Solution {
public:
    int uniquePaths(int a, int b) {
        int n = a + b - 2;
        int k = (a < b) ? a - 1 : b - 1;
        
        long long answer = 1;
        for(int i = 0 ; i < k ; i++) answer *= (n - i);
        for(int i = 1 ; i <= k ; i++) answer /= i;
        
        return answer;
    }
};