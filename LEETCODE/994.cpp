#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int freshCnt = 0;
        for(int i = 0 ; i < grid.size() ; i++) {
            for(int j = 0 ; j < grid[i].size() ; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1) {
                    freshCnt++;
                }
            }
        }
        
        if(freshCnt == 0) return 0;
        
        int minutes = 0;
        while(!q.empty()) {
            minutes++;
            int size = q.size();
            for(int i = 0 ; i < size ; i++) {
                auto cur = q.front();
                q.pop();
                
                for(int i = 0 ; i < 4 ; i++) {
                    int nextRow = cur.first + dir[i].first;
                    int nextCol = cur.second + dir[i].second;
                    
                    if(nextRow >= 0 && nextRow < grid.size() && nextCol >= 0 && nextCol < grid[nextRow].size() && grid[nextRow][nextCol] == 1) {
                        grid[nextRow][nextCol] = 2;
                        q.push({nextRow, nextCol});
                        
                        if(--freshCnt == 0) return minutes;
                    }
                }            
            }
        }
        
        return -1;
    }
    
private:
    pair<int, int> dir[4] = {
        {-1, 0},
        {0, -1},
        {1, 0},
        {0, 1}
    };
};