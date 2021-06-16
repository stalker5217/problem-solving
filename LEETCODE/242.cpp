#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sArr(26, 0);
        vector<int> tArr(26, 0);
        
        for(int i = 0 ; i < s.size() ; i++) sArr[s[i] - 'a']++;
        for(int i = 0 ; i < t.size() ; i++) tArr[t[i] - 'a']++;
        
        bool result = true;
        for(int i = 0 ; i < 26 ; i++){
            if(sArr[i] != tArr[i]) {
                result = false;
                break;
            }
        }
        
        return result;
    }
};