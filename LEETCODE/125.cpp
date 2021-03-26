#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {        
        vector<char> charArr;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] >= 'a' && s[i] <= 'z') charArr.push_back(s[i]);
            else if(s[i] >= 'A' && s[i] <= 'Z') charArr.push_back(s[i] - 'A' + 'a');
            else if(s[i] >= '0' && s[i] <= '9') charArr.push_back(s[i]);
        }
        
        int start = 0;
        int end = charArr.size() - 1;
        bool isPalindrome = true;
        while(isPalindrome && start < end){
            if(charArr[start++] != charArr[end--]){
                isPalindrome = false;
                break;
            }
        }
        
        return isPalindrome;
    }
};