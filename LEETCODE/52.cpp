#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        boardSize = n;
        queenPos.assign(n, 0);
        answer = 0;
        dfs(0);
        
        return answer;
    }

private:
    int boardSize;
    vector<int> queenPos;
    int answer;
    
    void dfs(int row) {
        if (row == boardSize) {
            answer++;
            return;
        }
        
        for(int i = 0 ; i < boardSize ; i++) {
            queenPos[row] = i;
            if (isPromising(row)) {
                dfs(row + 1);
            }
        }
    }
    
    bool isPromising(int row) {
        for(int i = 0 ; i < row ; i++) {
            if (queenPos[i] == queenPos[row]) {
                return false;
            }
            
            if (abs(queenPos[row] - queenPos[i]) == abs(row - i)) {
                return false;
            }
        }
        
        return true;
    }
};