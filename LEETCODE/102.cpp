#include <vector>
#include <algorithm>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int height = getHeight(root, 0);
        vector<vector<int> > result(height);
        helper(root, 0, result);
        
        return result;
    }
    
    int getHeight(TreeNode* root, int level) {
        if(root == nullptr) return level;
        else return max(getHeight(root->left, level+1), getHeight(root->right, level+1));
    }
    
    void helper(const TreeNode* node, const int level, vector<vector<int> > & result) {
        if(node != nullptr) {
            result[level].push_back(node->val);
            helper(node->left, level+1, result);
            helper(node->right, level+1, result);
        }
    }
};