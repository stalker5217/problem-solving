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
    int diameterOfBinaryTree(TreeNode* root) {
        int answer = 0;
        helper(root, answer);
        return answer;
    }
    
    int helper(TreeNode* node, int& answer) {
        if (node == nullptr) {
            return 0;
        }
        
        int left = helper(node->left, answer);
        int right = helper(node->right, answer);
        
        if (left + right > answer) {
            answer = left + right;
        }
        
        return 1 + max(left, right);
    }
};