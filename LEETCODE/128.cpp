#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set sets(nums.begin(), nums.end());
        
        int answer = 0;
        for(int num : nums) {
            if (sets.find(num -1) == sets.end()) {
                int current = num;
                int length = 0;
                while(sets.find(current) != sets.end()) {
                    current++;
                    length++;
                }
                
                answer = max(answer, length);
            }
        }
        
        return answer;
    }
};