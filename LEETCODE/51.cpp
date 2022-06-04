#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        boardSize = n;
        queenPos.assign(n, 0);
        dfs(0);
        
        return answer;
    }
    
private:
    int boardSize;
    vector<int> queenPos;
    vector<vector<string>> answer;
    
    void dfs(int row) {
        if (row == boardSize) {
            vector<string> current(boardSize);
            for(int i = 0 ; i < boardSize ; i++) {
                string dots = "";
                for(int j = 0 ; j < boardSize ; j++) {
                    if (j == queenPos[i]) {
                        dots.push_back('Q');
                    }
                    else {
                        dots.push_back('.');
                    }
                }
  
                current[i] = dots;
            }
            
            answer.push_back(current);
            
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