#include <string>

using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.size() == 0) {
            return 0;
        }
        else if (s == string(s.rbegin(), s.rend())) {
            return 1;
        }
        else {
            return 2;
        }
    }
};