class Solution {
public:
    int findComplement(int num) {
        int answer = 0;
        long long p = 1;
        while(num >= p) {
            if((num & p) == 0) answer += p;
            p <<= 1;
        }
        
        return answer;
    }
};