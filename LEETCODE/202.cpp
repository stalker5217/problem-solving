#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        bool isHappy;
        
        vector<int> resultSet;
        int result = n;
        while(true) {
            int current = result;
            result = 0;
            while(current > 0) {
                result += (current % 10) * (current % 10);
                current /= 10;
            }
            
            if(result == 1) {
                isHappy = true;
                break;
            }
            
            if(find(resultSet.begin(), resultSet.end(), result) != resultSet.end()) {
                isHappy = false;
                break;
            }
			else resultSet.push_back(result);
        }
        
        return isHappy;
    }
};