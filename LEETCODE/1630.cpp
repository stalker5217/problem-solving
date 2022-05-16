#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> answer(l.size(), true);
        for(int i = 0 ; i < answer.size() ; i++) {
            if (l[i] == r[i]) continue;
            
            vector<int> cur(nums.begin() + l[i], nums.begin() + r[i] + 1);
            
            sort(cur.begin(), cur.end());
            const int diff = cur[1] - cur[0];
            for(int j = 1 ; j < cur.size() - 1 ; j++) {
                if(cur[j + 1] - cur[j] != diff) {
                    answer[i] = false;
                    break;
                }
            }
        }
        
        return answer;
    }
};