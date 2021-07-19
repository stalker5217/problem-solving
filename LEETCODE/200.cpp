#include <vector>

using namespace std;

class Solution {
private:
    pair<int, int> dir[4] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };
    int count = 0;
    
public:
    int numIslands(vector<vector<char>>& grid) {
        for(int i = 0 ; i < grid.size() ; i++) {
            for(int j = 0 ; j < grid[i].size() ; j++) {
                if(grid[i][j] == '1') {
                    ++count;
                    dfs(grid, i, j);
                }
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, int row, int col) {
        grid[row][col] = '2';
        for(int i = 0 ; i < 4 ; i++) {
            int nextRow = row + dir[i].first;
            int nextCol = col + dir[i].second;
            
            if(nextRow < 0 ||
               nextRow >= grid.size() ||
               nextCol < 0 ||
               nextCol >= grid[row].size() ||
               grid[nextRow][nextCol] != '1') continue;
            
            dfs(grid, row + dir[i].first, col + dir[i].second);
        }
    }
};