
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
    bool hasPathSum(TreeNode* node, int targetSum) {
        if(node == nullptr) return false;
        else if(node->left == nullptr && node->right == nullptr && targetSum == node->val) return true;
        else return 
            hasPathSum(node->left, targetSum - node->val) 
            || 
            hasPathSum(node->right, targetSum - node->val);
    }
};