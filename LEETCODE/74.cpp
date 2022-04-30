#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool exist = false;
        
        int row = 0;
        int col = matrix[0].size() - 1;
        
        while(row < matrix.size() && col >= 0) {
            if (target > matrix[row][col]) {
                row++;
            }
            else if (target < matrix[row][col]) {
                col--;
            }
            else if (target == matrix[row][col]) {
                exist = true;
                break;
            }
        }
        
        return exist;
    }
};