#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > pascalTriangle(numRows, vector<int>(0));

		for(int row = 0 ; row < numRows ; row++){
			pascalTriangle[row] = vector<int>(row + 1, 0);

			for(int col = 0 ; col <= row ; col++){
				if(col == 0 || col == row) pascalTriangle[row][col] = 1;
				else pascalTriangle[row][col] = pascalTriangle[row-1][col-1] + pascalTriangle[row-1][col];
			}
		}
        
        return pascalTriangle;
    }
};

int main(){
	Solution s;
	vector<vector<int> > result = s.generate(5);

	for(int i = 0 ; i < result.size() ; i++){
		for(int j = 0 ; j < result[i].size() ; j++){
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
}