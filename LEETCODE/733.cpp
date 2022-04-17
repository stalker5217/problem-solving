#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        vector<vector<bool> > visit(image.size(), vector<bool>(image[0].size(), false));
        
        visit[sr][sc] = true;
        dfs(
            image, 
            visit, 
            sr, 
            sc, 
            image[sr][sc], 
            newColor
        );
        
        return image;
    
    }
    
    void dfs(vector<vector<int>> & image, vector<vector<bool>> & visit, int r, int c, int color, int newColor) {

        image[r][c] = newColor;
        
        for(int i = 0 ; i < 4 ; i++) {
            int nextRow = r + dir[i].first;
            int nextCol = c + dir[i].second;
            
            if (nextRow >= 0 && nextRow < image.size() && nextCol >= 0 && nextCol < image[nextRow].size() && !visit[nextRow][nextCol] && image[nextRow][nextCol] == color) {
                visit[nextRow][nextCol] = true;
                
                dfs(
                    image, 
                    visit, 
                    nextRow, 
                    nextCol, 
                    color, 
                    newColor
                );
            }
        }
    }

private:
    pair<int, int> dir[4] = {
        {-1, 0},
        {0, -1},
        {1, 0},
        {0, 1}
    };
};