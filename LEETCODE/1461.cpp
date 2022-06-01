#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) {
            return false;
        }
        
        unordered_set<string> binarySet;
        for(int i = 0 ; i < s.size() - k + 1 ; i++) {
            binarySet.insert(s.substr(i, k));
        }
           
        return (1 << k) == binarySet.size();
    }
};