#include <vector>
#include <string>

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
    vector<string> ret;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        helper(root, "");
        return ret;
    }
    
    void helper(TreeNode* node, string path) {
        path += to_string(node->val);
        
        if(node->left == nullptr && node->right == nullptr) {
            ret.push_back(path);
        }
        
        path += "->";
        
        if(node->left != nullptr) helper(node->left, path);
        if(node->right != nullptr) helper(node->right, path);
    }
};