#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > ret;
        
        sort(intervals.begin(), intervals.end());
        
        vector<int> cur = intervals[0];
        for(auto interval : intervals) {
            if(cur[1] >= interval[0]) cur[1] = max(cur[1], interval[1]);
            else {
                ret.push_back(cur);
                cur = interval;
            }
        }
        ret.push_back(cur);
        
        return ret;
    }
};