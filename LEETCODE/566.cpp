#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (mat.size() * mat[0].size() != r * c) return mat;
        
        queue<int> q;
        for(int i = 0 ; i < mat.size() ; i++) {
            for(int j = 0 ; j < mat[i].size() ; j++) {
                q.push(mat[i][j]);
            }
        }
        
        vector<vector<int> > ret(r, vector<int>(c));
        for(int i = 0 ; i < ret.size() ; i++) {
            for(int j = 0 ; j < ret[i].size() ; j++) {
                ret[i][j] = q.front();
                q.pop();
            }
        }
        
        return ret;
    }
};