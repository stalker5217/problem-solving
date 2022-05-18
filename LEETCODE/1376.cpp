#include <vector>

using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int answer = -1;
        
        vector<int> cache(n, -1);
        for(int i = 0 ; i < n ; i++) {
            int time = informTime[i];
            int managerId = manager[i];
                
            while(managerId != -1) {
                if (cache[managerId] >= 0) {
                    time += cache[managerId];
                    break;
                }
                
                time += informTime[managerId];
                managerId = manager[managerId];
            }
            
            answer = max(answer, time);
            cache[i] = time;
        }
        
        return answer;
    }
};