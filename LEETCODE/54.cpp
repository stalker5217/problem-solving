#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int total = matrix.size() * matrix[0].size();
        vector<int> answer(total);
        
        int cnt = 0;
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size()));
        int row = 0;
        int col = 0;
        int curDir = 0;
        while(cnt < total) {
            answer[cnt++] = matrix[row][col];
            visited[row][col] = true;
            
            if (!keepGoing(visited, {row + dir[curDir].first, col + dir[curDir].second})) {
                curDir = (curDir + 1) % 4;
            }
            
            row += dir[curDir].first;
            col += dir[curDir].second;
        }
        
        return answer;
    }

private:
    pair<int, int> dir[4] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    
    bool keepGoing(vector<vector<bool>>& visited, pair<int, int> pos) {
        return pos.first >= 0 &&
            pos.first < visited.size() &&
            pos.second >= 0 &&
            pos.second < visited[pos.first].size() &&
            !visited[pos.first][pos.second];
    }
};