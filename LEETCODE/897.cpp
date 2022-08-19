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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1); // dummy
        helper(root, dummy);
        
        return dummy->right;
    }
    
    TreeNode* helper(TreeNode* node, TreeNode* ret) {
        if (node->left) {
            ret = helper(node->left, ret);
        }
        
        ret->right = new TreeNode(node->val);
        ret = ret->right;
        
        if (node->right) {
            ret = helper(node->right, ret);
        }
        
        return ret;
    }
};