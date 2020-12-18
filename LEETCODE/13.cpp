#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap;
        
        romanMap['I'] = 1;
        romanMap['V'] = 5;
        romanMap['X'] = 10;
        romanMap['L'] = 50;
        romanMap['C'] = 100;
        romanMap['D'] = 500;
        romanMap['M'] = 1000;
        
        int ret = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(i + 1 < s.size() && romanMap[s[i]] < romanMap[s[i+1]]){
                ret += romanMap[s[i+1]] - romanMap[s[i]];
                i++;
            }
            else ret += romanMap[s[i]];
        }
        
        return ret;
    }
};