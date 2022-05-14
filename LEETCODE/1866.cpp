#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0 ; i < 4 ; i++) {
            if (mat == target) 
                return true;
            
            rotate(mat);
        }
        
        return false;
    }

private:
    // rotate 90 degree
    void rotate(vector<vector<int>>& arr) {
        for(int i = 0 ; i < arr.size() ; i++) {
            for(int j = i ; j < arr[i].size() ; j++) {
                swap(arr[i][j], arr[j][i]);
            }
        }
        
        for(int i = 0 ; i < arr.size() ; i++) {
            reverse(arr[i].begin(), arr[i].end());
        }
    }
};