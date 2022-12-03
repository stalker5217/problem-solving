#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](auto a, auto b) {
            if (a[0] != b[0]) {
                return a[0] > b[0];
            } else {
                return a[1] < b[1];
            }
        });
        
        vector<vector<int>> answer;
        for(auto m : people) {
            answer.insert(answer.begin() + m[1], m);
        }
        
        return answer;
    }
};