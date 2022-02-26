#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int width;
        int s = sqrt(area);
        for(int i = s ; i >= 1 ; i--) {
            if(area % i == 0) {
                width = i;
                break;
            }
        }
        
        vector<int> answer(2);
        answer[0] = area / width;
        answer[1] = width;
        
        return answer;
    }
};