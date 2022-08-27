#include <algorithm>

using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int start = -1, end = -1;
        int pos = 1;
        int answer = 0;
        while(n > 0) {
            if (n & 1) {
                end = pos;
                
                if (start > 0) {
                    answer = max(answer, end - start);
                }
                
                start = end;
            }
            
            pos++;
            n >>= 1;
        }
        
        return answer;
    }
};