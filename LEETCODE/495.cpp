#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int prev = -1;
        int sum = 0;
        for(int time : timeSeries) {
            sum += time + duration - max(time, prev);
            prev = time + duration;
        }
        
        return sum;
    }
};