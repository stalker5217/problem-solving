#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        int i = s.size() - 1;
        string answer = "";
        while(i >= 0) {
            int cur = 0;
            if(s[i] == '#') {
                i--;
                cur = s[i--] - '0';
                cur += (s[i--] - '0') * 10;
                answer.push_back((char)('a' - 1 + cur));
            }
            else {
                cur = s[i--] - '0';
                answer.push_back((char)('a' - 1 + cur));
            }
        }
        
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};