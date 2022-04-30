#include <vector>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
    
        for(int a = 0, b = 0 ; a < mat.size() ; a++, b++) {
            sum += mat[a][b];
        }
        
        for(int a = 0, b = mat[0].size() - 1 ; a < mat.size() ; a++, b--) {
            sum += mat[a][b];
        }
        
        if (mat.size() % 2) {
            int middle = mat.size() / 2;
            sum -= mat[middle][middle];
        }
        
        return sum;
    }
};