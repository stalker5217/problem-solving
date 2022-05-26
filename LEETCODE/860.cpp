#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCnt = 0;
        int tenCnt = 0;
        
        for(int cur : bills) {
            if (cur == 5) {
                fiveCnt++;
            }
            else if (cur == 10) {
                tenCnt++;
                if (fiveCnt == 0) {
                    return false;
                }   
                else {
                    fiveCnt--;
                }
                    
            }
            else if (cur == 20) {
                if (tenCnt > 0 && fiveCnt > 0) {
                    tenCnt--;
                    fiveCnt--;
                }
                else if (fiveCnt >= 3) {
                    fiveCnt -= 3;
                }
                else {
                    return false;
                }
            }
        }
        
        return true;
    }
};