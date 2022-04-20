class Solution {
public:
    int countOdds(int low, int high) {
        int answer = answer = (high - low + 1) / 2;
        
        if ((high - low + 1) % 2 == 1) {
            if (low & 1 == 1) answer += 1;
        } 
        
        return answer;
    }
};