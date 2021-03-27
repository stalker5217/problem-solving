#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int start = 0, end = s.size() - 1 ; start < end ; start++, end--){
           char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
        }
    }
};