#include <vector>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int baseX = coordinates[0][0] - coordinates[1][0];
        int baseY = coordinates[0][1] - coordinates[1][1];
        
        bool isStraight = true;
        for(int i = 1 ; i < coordinates.size() - 1 ; i++) {
            int dx = coordinates[i][0] - coordinates[i+1][0];
            int dy = coordinates[i][1] - coordinates[i+1][1];
            
            if(baseX * dy != baseY * dx) {
                isStraight = false;
                break;
            }
        }
        
        return isStraight;
    }
};