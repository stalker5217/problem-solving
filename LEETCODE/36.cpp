#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<vector<bool>> rowHash(9, vector<bool>(10, false));
        vector<vector<bool>> colHash(9, vector<bool>(10, false));
        vector<vector<bool>> subBoxHash(9, vector<bool>(10, false));
        for(int i = 0 ; i < board.size() ; i++) {
            for(int j = 0 ; j < board[i].size() ; j++) {
                if (board[i][j] != '.') {
                    int cur = board[i][j] - '0';
                    
                    if (rowHash[i][cur]) return false;
                    else rowHash[i][cur] = true;
                    
                    if (colHash[j][cur]) return false;
                    else colHash[j][cur] = true;
                    
                    if (subBoxHash[(i / 3) * 3  + (j / 3)][cur]) return false;
                    else subBoxHash[(i / 3) * 3  + (j / 3)][cur] = true;
                }
            }
        }
        
        return true;
    }
};