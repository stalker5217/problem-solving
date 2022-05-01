#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        helper(s, 0);
        
        return answer;
    }
    
private:
    vector<string> answer;
    
    void helper(string s, int offset) {
        if (offset == s.size()) {
            answer.push_back(s);
            return;
        }
        

        helper(s, offset + 1);

        if (islower(s[offset])) {
            s[offset] = toupper(s[offset]);
            helper(s, offset + 1);
            s[offset] = tolower(s[offset]);
        }
        else if (isupper(s[offset])) {
            s[offset] = tolower(s[offset]);
            helper(s, offset + 1);
            s[offset] = toupper(s[offset]);
        }
    }
};