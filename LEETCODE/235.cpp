#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
	TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;
        
        int lower = min(p->val, q->val);
        int upper = max(p->val, q->val);
        
        if (root->val >= lower && root->val <= upper) {
            return root;
        }
        else if (root->val > upper) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (root->val < lower){
            return lowestCommonAncestor(root->right, p, q);
        }
        
        return nullptr;
    }
};