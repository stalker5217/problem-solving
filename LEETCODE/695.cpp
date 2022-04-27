#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool> > visited(grid.size(), vector<bool>(grid[0].size(), false));
        int maxArea = 0;
        for (int i = 0 ; i < grid.size() ; i++) {
            for(int j = 0 ; j < grid[i].size() ; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    pair<int, int> pos = {i, j};
                    maxArea = max(maxArea, getArea(grid, visited, pos));
                }
            } 
        }
        
        return maxArea;
    }
    
private:
    pair<int, int> dir[4] = {
        {-1, 0},
        {0, -1},
        {1, 0},
        {0, 1}
    };
    
    int getArea(vector<vector<int> >& grid, vector<vector<bool> >& visited, pair<int, int> pos) {
        int area = 0;
        visited[pos.first][pos.second] = true;
        
        queue<pair<int, int> > q;
        q.push(pos);
        
        while (!q.empty()) {
            area++;
            
            pair<int, int> cur = q.front();
            q.pop();
            
            for (int i = 0 ; i < 4 ; i++) {
                int nextRow = cur.first + dir[i].first;
                int nextCol = cur.second + dir[i].second;
                
                if (nextRow >= 0 
                    && nextRow < grid.size() 
                    && nextCol >= 0 
                    && nextCol < grid[nextRow].size() 
                    && grid[nextRow][nextCol] == 1 
                    && !visited[nextRow][nextCol]
                   ) {
                    visited[nextRow][nextCol] = true;
                    q.push({nextRow, nextCol});
                }
            }
        }
        
        return area;
    }
};