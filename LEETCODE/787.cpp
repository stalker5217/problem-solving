#include <vector>

using namespace std;

class Solution {
private:
    const int INF = 987654321;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n, INF);
        distance[src] = 0;
        
        for(int i = 0 ; i <= k ; i++) {
            vector<int> temp(distance.begin(), distance.end());
            for(auto flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];
                
                temp[to] = min(temp[to], distance[from] + price);
            }
            
            distance = temp;
        }
        
        return distance[dst] == INF ? -1 : distance[dst];
    }
};