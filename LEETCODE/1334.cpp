#include <vector>

using namespace std;

class Solution {
private:
    const int INF = 987654321;
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n, INF));
        
        for(int i = 0 ; i < distance.size() ; i++) {
            distance[i][i] = 0;
        }
        
        for(auto edge : edges) {
            distance[edge[0]][edge[1]] = edge[2];
            distance[edge[1]][edge[0]] = edge[2];
        }
        
        for(int k = 0 ; k < n ; k++) {
            for(int i = 0 ; i < n ; i++) {
                for(int j = 0 ; j < n ; j++) {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
        
        int minCount = n + 1;
        int answer = -1;
        for(int i = 0 ; i < n ; i++) {
            int count = 0;
            for(int j = 0 ; j < n ; j++) {
                if (distance[i][j] <= distanceThreshold) {
                    count++;
                }
            }
                    
            if (count <= minCount) {
                minCount = count;
                answer = i;
            }
        }
        
        return answer;
    }
};