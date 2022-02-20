#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> charMap;
        for(char cur : s) {
            charMap[cur]++;
        }
        
        int answer = -1;
        for(int i = 0 ; i < s.size() ; i++) {
            if(charMap[s[i]] == 1) {
                answer = i;
                break;
            }
        }
        
        return answer;
    }
};