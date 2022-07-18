#include <string>

using namespace std;

class Solution {
private:
    string toBinary(int n) {
        string ret = "";
        while(n > 0) {
            string append = (n & 1) ? "1" : "0";
            ret.insert(0, append);
            n >>= 1;
        }
        
        return ret;
    }
    
public:
    bool queryString(string s, int n) {
        for(int i = n ; i >= (n >> 1) ; i--) {
            if (s.find(toBinary(i)) == string::npos) {
                return false;
            }
        }
        
        return true;
    }
};