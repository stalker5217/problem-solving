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
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
    
    void helper(TreeNode* node){
        if(node == nullptr) return;
        
        TreeNode* temp = node->right;
        node->right = node->left;
        node->left = temp;
        
        helper(node->left);
        helper(node->right);
    }
};