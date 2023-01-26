#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for(auto edge : edges) {
            indegree[edge[1]]++;
        }

        vector<int> answer;
        for(int i = 0 ; i < indegree.size() ; i++) {
            if (indegree[i] == 0) {
                answer.push_back(i);
            }
        }

        return answer;
    }
};