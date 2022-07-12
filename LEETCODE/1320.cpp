#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<char>> layout = {
        {'A', 'B', 'C', 'D', 'E', 'F'},
        {'G', 'H', 'I', 'J', 'K', 'L'},
        {'M', 'N', 'O', 'P', 'Q', 'R'},
        {'S', 'T', 'U', 'V', 'W', 'X'},
        {'Y', 'Z'}
    };
    
    int getDistance(char start, char end) {
        if (start == 'Z' + 1) {
            return 0;
        }
        
        int sx, sy;
        int ex, ey;
        for(int i = 0 ; i < layout.size() ; i++) {
            for(int j = 0 ; j < layout[i].size() ; j++) {
                if (layout[i][j] == start) {
                    sx = i;
                    sy = j;
                }
                
                if (layout[i][j] == end) {
                    ex = i;
                    ey = j;
                }
            }
        }
        
        return abs(ex - sx) + abs(ey - sy);
    }
    
    vector<vector<vector<int>>> cache;
    int dfs(const string s, int index, int prevLeft, int prevRight) {
        if (index == s.size()) {
            return 0;
        }
        
		int& ret = cache[index][prevLeft - 'A'][prevRight - 'A'];
		if (ret != -1) {
			return ret;
		}

        int leftCost = getDistance(prevLeft, s[index]) + dfs(s, index + 1, s[index], prevRight);
        int rightCost = getDistance(prevRight, s[index]) + dfs(s, index + 1, prevLeft, s[index]);

		return ret = min(leftCost, rightCost);
    }
    
public:
    int minimumDistance(string word) {
        cache.resize(word.size(), vector<vector<int>>(27, vector<int>(27, -1)));
		dfs(word, 0, 'Z' + 1, 'Z' + 1);
    }
};