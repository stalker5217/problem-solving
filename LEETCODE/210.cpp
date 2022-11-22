#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacent(numCourses);
        
        vector<int> indegree(numCourses);
        
        for(auto prerequest : prerequisites) {
            adjacent[prerequest[1]].push_back(prerequest[0]);
            indegree[prerequest[0]]++;
        }
        
        queue<int> q;
        for(int i = 0 ; i < indegree.size() ; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> answer;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            
            answer.push_back(cur);
            for(int to : adjacent[cur]) {
                if(--indegree[to] == 0) {
                    q.push(to);
                }
            }
        }
        
        if (answer.size() < numCourses) {
            answer.clear();
        }
        
        return answer;
    }
};