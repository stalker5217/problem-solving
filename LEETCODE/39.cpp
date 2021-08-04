#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int> > ret;
    vector<int> cur;
    
    void helper(vector<int>& candidates, 
                const int target, 
                int curIndex, 
                int sum)
    {
        if(target < sum) return;
        else if(target == sum) {
            ret.push_back(cur);
            return;
        }
        
        for(int i = curIndex ; i < candidates.size() ; i++) {
            sum += candidates[i];
            cur.push_back(candidates[i]);
            helper(candidates, target, i, sum);
            sum -= candidates[i];
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates, target, 0, 0);
        
        return ret;
    }
};