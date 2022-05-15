#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, vector<int>>> dist;
        for(auto point : points) {
            int d = point[0] * point[0] + point[1] * point[1];
            dist.push_back({d, point});
        }
        
        sort(dist.begin(), dist.end());
        
        vector<vector<int>> answer;
        for(int i = 0 ; i < k ; i++) {
            answer.push_back(dist[i].second);
        }
        
        return answer;
    }
};