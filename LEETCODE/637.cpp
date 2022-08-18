#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> nodesOfLevel;
        vector<double> answer;
        helper(root, 0, nodesOfLevel);
        for(vector<int> nodes : nodesOfLevel) {
            long long sum = 0;
            for(int node : nodes) {
                sum += node;
            }
            
            answer.push_back((double) sum / nodes.size());
        }
        
        
        return answer;
    }
    
    void helper(TreeNode* node, int level, vector<vector<int>> & nodesOfLevel) {
        if (nodesOfLevel.size() <= level) nodesOfLevel.push_back(vector<int>(1, node->val));
        else nodesOfLevel[level].push_back(node->val);
        
        if (node->left) {
            helper(node->left, level + 1, nodesOfLevel);
        }
        
        if (node->right) {
            helper(node->right, level + 1, nodesOfLevel);
        }
    }
};