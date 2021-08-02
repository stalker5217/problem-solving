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
private:
    const int NOT_ASSIGN = 101;
    
    vector<int> result;
    
    void helper(TreeNode* node, int level) {
        if(node == nullptr) return;
        
        if(result[level] == NOT_ASSIGN) result[level] = node->val;

        helper(node->right, level + 1);
        helper(node->left, level + 1);   
    }
    
    int getHeight(TreeNode* node, int level) {
        if(node == nullptr) return level;
        else return max(getHeight(node->left, level+1), getHeight(node->right, level+1));
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        result.assign(getHeight(root, 0), NOT_ASSIGN);
        helper(root, 0);
        
        return result;
    }
};