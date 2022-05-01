#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string answer = "";
        
        int index1 = 0;
        int index2 = 0;
        
        while(index1 < word1.size() || index2 < word2.size()) {
            if (index1 < word1.size()) {
                answer += word1[index1++];
            }
            
            if (index2 < word2.size()) {
                answer += word2[index2++];
            }
        }
        
        return answer;
    }
};