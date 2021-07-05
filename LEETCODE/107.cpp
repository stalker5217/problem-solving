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
    int height;
    vector<vector<int> > ret;
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        height = getHeight(root, 0);
        ret.assign(height, vector<int>(0));
        helper(root, 0);
        
        return ret;
    }
    
    int getHeight(TreeNode* node, int height) {
        if(node == nullptr) return height;
        return max(getHeight(node->left, height+1), getHeight(node->right, height+1));
    }
    
    void helper(TreeNode* node, int level) {
        if(node == nullptr) return;
        
        ret[height - level - 1].push_back(node->val);
        helper(node->left, level+1);
        helper(node->right, level+1);
    }
};