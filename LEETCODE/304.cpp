#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        partialSum.assign(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        partialSum[0][0] = matrix[0][0];
        
        for(int i = 1 ; i < matrix.size() ; i++) {
            partialSum[i][0] = partialSum[i-1][0] + matrix[i][0];
        }
        
        for(int i = 1 ; i < matrix[0].size() ; i++) {
            partialSum[0][i] = partialSum[0][i-1] + matrix[0][i];
        }
        
        for(int i = 1 ; i < matrix.size() ; i++) {
            for(int j = 1 ; j < matrix[i].size() ; j++) {
                partialSum[i][j] = partialSum[i-1][j] + partialSum[i][j-1] - partialSum[i-1][j-1] + matrix[i][j]; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int answer = partialSum[row2][col2];
        if (row1 > 0) answer -= partialSum[row1-1][col2];
        if (col1 > 0) answer -= partialSum[row2][col1-1];
        if (row1 > 0 && col1 > 0) answer += partialSum[row1-1][col1-1];
        
        return answer;
    }
    
private:
    vector<vector<int>> partialSum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */