#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ret = "";
        while(columnNumber){
            ret.push_back('A' + (columnNumber - 1) % 26);
            columnNumber = (columnNumber - 1) / 26;
        }
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};