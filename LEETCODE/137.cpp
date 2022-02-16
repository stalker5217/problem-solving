#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num : nums) freq[num]++;
        
        int answer = 0;
        for(auto cur : freq) {
            if(cur.second == 1) {
                answer = cur.first;
            }
        }
        
        return answer;
    }
};