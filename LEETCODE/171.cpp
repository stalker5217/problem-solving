#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int answer = 0;
        for(char cur : columnTitle) {
            answer *= 26;
            answer += (cur - 'A' + 1);
        }
        
        return answer;
    }
};