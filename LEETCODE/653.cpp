#include <unordered_set>

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
    bool findTarget(TreeNode* root, int k) {
        target = k;
        preOrder(root);
        return possible;
    }
    
private:
    unordered_set<int> valSet;
    bool possible = false;
    int target;
    
    void preOrder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        
        if (valSet.find(target - node->val) != valSet.end()) {
            possible = true;
            return;
        }
        
        valSet.insert(node->val);
        preOrder(node->left);
        preOrder(node->right);
    }
};