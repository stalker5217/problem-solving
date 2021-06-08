#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int answer = -1;
        for(int cur : prices) {
            answer = (cur - min) > answer ? (cur - min) : answer;
            if(min > cur) min = cur;
        }
        
        return answer;
    }
};