#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> lexical;
        for(int i = 0 ; i < order.size() ; i++) {
            lexical[order[i]] = i;
        }
        
        for(int i = 0 ; i < words.size() - 1 ; i++) {
            if (!compare(words[i], words[i+1], lexical)) return false;
        }
        
        return true;
    }

private:
    bool compare(string s1, string s2, unordered_map<char, int> lexical) {
        int length = min(s1.size(), s2.size());

        for(int i = 0 ; i < length ; i++) {
            if (lexical[s1[i]] < lexical[s2[i]]) return true;
            else if (lexical[s1[i]] > lexical[s2[i]]) return false;
        }        
        
        if(s1.size() > s2.size()) return false;
        
        return true;
    }
};