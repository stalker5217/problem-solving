#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bitOfWords(words.size());
        for(int i = 0 ; i < words.size() ; i++) {
            int bit = 0;
            for(int j = 0 ; j < words[i].size() ; j++) {
                int shift = words[i][j] - 'a';
                bit |= (1 << shift);
            }
            
            bitOfWords[i] = bit;
        }
        
        int answer = 0;
        for(int i = 0 ; i < words.size() ; i++) {
            for(int j = i + 1 ; j < words.size() ; j++) {
                if ((bitOfWords[i] & bitOfWords[j]) == 0) {
                    int curLength = words[i].size() * words[j].size();
                    answer = max(answer, curLength);  
                }
            }
        }
        
        return answer;
    }
};