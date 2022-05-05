#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        
        vector<vector<int>> answer(mat.size(), vector<int>(mat[0].size()));
        for(int i = 0 ; i < mat.size() ; i++) {
            for(int j = 0 ; j < mat[i].size() ; j++) {
                if(mat[i][j] == 1) {
                    answer[i][j] = -1;
                }
                else {
                    q.push({i, j});
                }
            }
        }
        
        while(!q.empty()) {
            auto pos = q.front();
            q.pop();

            for(int i = 0 ; i < 4 ; i++) {
                int nextRow = pos.first + dir[i].first;
                int nextCol = pos.second + dir[i].second;

                if (nextRow >= 0 && nextRow < mat.size() && nextCol >= 0 && nextCol < mat[nextRow].size() && answer[nextRow][nextCol] == -1) {
                    answer[nextRow][nextCol] = answer[pos.first][pos.second] + 1;
                    q.push({nextRow, nextCol});
                }
            }
        }
        
        return answer;
    }
    
private:
    pair<int, int> dir[4] = {
        {-1, 0},
        {0, -1},
        {1, 0},
        {0, 1}
    };
};