#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> magazineCnt(26, 0);
        for(int i = 0 ; i < magazine.size() ; i++) {
            magazineCnt[magazine[i] - 'a']++;
        }
        
        for(int i = 0 ; i <ransomNote.size() ; i++) {
            if(magazineCnt[ransomNote[i] - 'a']-- <= 0) return false;
        }
        
        return true;
    }
};