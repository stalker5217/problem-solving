#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> answer;
        
        int sum = 0;
        for(int i = 1 ; i < n ; i++) {
           answer.push_back(i);
           sum += i;
        }
        
        answer.push_back(-sum);
        
        return answer;
    }
};