#include <cmath>
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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        if(abs(getHeight(root->left) - getHeight(root->right)) <= 1
          && isBalanced(root->left)
          && isBalanced(root->right)) return true;
        
        return false;
    }
    
    int getHeight(TreeNode* node){
        if(node == nullptr) return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
};