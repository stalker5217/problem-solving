#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int current = 1;
        vector<string> ret;
        
        for(int i = 0 ; i < target.size() ; current++) {
            if (current == target[i]) {
                ret.push_back("Push");
                i++;
            } else {
                ret.push_back("Push");
                ret.push_back("Pop");
            }
        }
        
        return ret;
    }
};