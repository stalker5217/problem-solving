#include <vector>

using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    
public:
    DisjointSet(int n)
    : parent(n) {
        for(int i = 0 ; i < n ; i++) {
            parent[i] = i;
        }
    }
    
    int find(int u) {
        if (parent[u] == u) {
            return u;
        } else {
            return find(parent[u]);
        }
    }
    
    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        
        if (u == v) {
            return;
        }
        
        parent[u] = v;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int, pair<int, int>>> edges;
        for(int i = 0 ; i < points.size() ; i++) {
            for(int j = i + 1 ; j < points.size() ; j++) {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({cost, {i, j}});
            }
        }
        
        sort(edges.begin(), edges.end());
  
        DisjointSet disjointSet(points.size());
        
        int minCost = 0;
        for(auto edge : edges) {
            int cost = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            
            if (disjointSet.find(u) == disjointSet.find(v)) {
                continue;
            }
            
            disjointSet.merge(u, v);
            minCost += cost;
        }
        
        return minCost;
    }
};