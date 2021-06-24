#include <vector>

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
    vector<vector<int> > ret;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int height = getHeight(root, 0);
        ret.assign(height, vector<int>(0));
        
        preorder(root, 0);
        
        for(int i = 1 ; i < ret.size() ; i+=2) {
            reverse(ret[i].begin(), ret[i].end());
        }
        
        return ret;
    }
    
    int getHeight(TreeNode* node, int level) {
        if(node == nullptr) return level;
        else return max(getHeight(node->left, level+1), getHeight(node->right, level+1));
    }
    
    void preorder(TreeNode* node, int level) {
        if(node == nullptr) return;
        
        ret[level].push_back(node->val);
            
        preorder(node->left,  level+1);
        preorder(node->right, level+1);
    }
};