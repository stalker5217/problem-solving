#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](const int a, const int b) {
            int ca = a, cb= b;
            int bitCnt1 = 0, bitCnt2 = 0;
            while(ca > 0) {
                if ((ca & 1) == 1) bitCnt1++;
                ca >>= 1;
            }
            
            while(cb > 0) {
                if ((cb & 1) == 1) bitCnt2++;
                cb >>=  1;
            }

            return (bitCnt1 != bitCnt2) ? bitCnt1 < bitCnt2 : a < b;
        });
        
        return arr;
    }
};