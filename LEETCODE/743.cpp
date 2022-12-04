#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    const int INF = 987654321;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int> > > adjacent(n + 1);
        for(auto time : times) {
            adjacent[time[0]].push_back({time[1], time[2]});
        }
        
        vector<int> distance(n + 1, INF);
        distance[k] = 0;
        
        priority_queue<pair<int, int>> pq;
        pq.push({0, k});
        
        while(!pq.empty()) {
            int cost = -pq.top().first;
            int pos = pq.top().second;
            pq.pop();
            
            if (distance[pos] < cost) {
                continue;
            }
            
            for(int i = 0 ; i < adjacent[pos].size() ; i++) {
                int target = adjacent[pos][i].first;
                int viaCost = cost + adjacent[pos][i].second;
                
                if (viaCost < distance[target]) {
                    distance[target] = viaCost;
                    pq.push({-viaCost, target});
                }
            }
        }
        
        int maxValue = *max_element(distance.begin() + 1, distance.end());
        
        return maxValue == INF ? -1 : maxValue;
    }
};