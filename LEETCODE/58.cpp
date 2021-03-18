#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int startIndex = s.size() - 1;
        while(startIndex > 0 && s[startIndex] == ' ') startIndex--;
        
        for(int i = 0 ; i <= startIndex ; i++){
            if(s[startIndex - i] == ' ') return i;
        }
        
        return startIndex + 1;
    }
};