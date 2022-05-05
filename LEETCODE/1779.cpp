#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int answer = -1;
        int minDist = 10000000;
        for (int i = 0 ; i < points.size() ; i++) {
            if (x == points[i][0] || y == points[i][1]) {
                int dist = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (minDist > dist) {
                    minDist = dist;
                    answer = i;
                }
            }
        }
        
        return answer;
    }
};