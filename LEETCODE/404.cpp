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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root, false, sum);
        return sum;
    }
    
    void helper(TreeNode* node, bool isLeft, int& sum) {
        if (node->left == nullptr && node->right == nullptr && isLeft) {
            sum += node->val;
            return;
        }
        
        if (node->left != nullptr)  helper(node->left, true, sum);
        if (node->right != nullptr) helper(node->right, false, sum);
    }
};