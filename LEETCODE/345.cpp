#include <string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        
        for(int start = 0, end = s.size() - 1 ; ; start++, end--){
            while(start < s.size() && !isVowels(s[start])) start++;
            while(end >= 0 && !isVowels(s[end])) end--;
            
            if(start >= end) break;
            
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
        }
                
        return s;
    }
    
private:
    bool isVowels(char ch){
        if(ch == 'a' 
           || ch == 'e' 
           || ch == 'i' 
           || ch =='o' 
           || ch == 'u' 
           || ch == 'A' 
           || ch == 'E' 
           || ch == 'I'
           || ch =='O' 
           || ch == 'U') return true;
        else return false;
    }
};