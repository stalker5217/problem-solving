#include <string>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int upDown = 0;
        int rightLeft = 0;
        
        for(int i = 0 ; i < moves.size() ; i++) {
            if (moves[i] == 'U') upDown++;
            else if (moves[i] == 'D') upDown--;
            else if (moves[i] == 'L') rightLeft--;
            else if (moves[i] == 'R') rightLeft++;
        }
        
        return upDown == 0 && rightLeft == 0;
    }
};