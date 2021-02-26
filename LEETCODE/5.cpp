#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        while(n){
            for(int start = 0 ; start + n <= s.size() ; start++){
                
                bool isPalindrom = true;
                for(int i = 0 ; i < n / 2 ; i++){
                    if(s[start + i] != s[start + n - i - 1]){
                        isPalindrom = false;
                        break;
                    }
                }

                if(isPalindrom) return s.substr(start, n);
            }
            n--;
        }
        
        return "";
    }
};