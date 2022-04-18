#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> picked;
        combination(picked, n, 1, k);
        
        return answer;
    }
    
    void combination(vector<int> picked, int n, int offset, int remain) {
        if (remain == 0) {
            answer.push_back(picked);
            return;
        }
        
        for(int i = offset ; i <= n - remain + 1 ; i++) {
            picked.push_back(i);
            combination(picked, n, i + 1, remain - 1);
            picked.pop_back();
        }
    }

private:
    vector<vector<int> > answer;
};