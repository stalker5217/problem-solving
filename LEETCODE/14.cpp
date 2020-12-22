#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        
        int shortestLen = 200;
        for(string s : strs){
            shortestLen = min(shortestLen, s.size());
        }
        if(shortestLen == 0) return "";
        
        int answer = shortestLen;
        bool catchAnswer = false;
        for(int i = 0 ; i < shortestLen ; i++){
            for(string s : strs){
                if(s[i] != strs[0][i]){
                    answer = i;
                    catchAnswer = true;
                    break;
                }
            }
            if(catchAnswer) break;
        }
        
        return strs[0].substr(0, answer);
    }

private:
    int min(int a, int b){
        return (a < b) ? a : b;
    }
};