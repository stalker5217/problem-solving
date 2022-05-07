#include <climits>

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
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
    
private:
    bool check(TreeNode* cur, long long min, long long max) {
        if (cur == nullptr) {
            return true;
        }
        
        if (cur->val <= min || cur->val >= max) {
            return false;
        }
        
        bool left = check(cur->left, min, cur->val);
        bool right = check(cur->right, cur->val, max);
    
        return left & right;    
    }
};