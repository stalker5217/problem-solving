#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret;
        
        for(int i = 0 ; i <= n ; i++) {
            int target = i;
            int cnt = 0;
            while(target > 0) {
                if((target & 1) == 1) cnt++;
                target >>= 1;
            }
            
            ret.push_back(cnt);
        }
        
        return ret;
    }
};