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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, 0, preorder.size() - 1,
                               inorder, 0, inorder.size() - 1
                              );
    }

private:
    TreeNode* buildTreeHelper(
        vector<int>& preorder, int preStart, int preEnd,
        vector<int>& inorder, int inStart, int inEnd)
    {
        if(preStart > preEnd || inStart > inEnd) return nullptr;
        
        int rootValue = preorder[preStart];
        int rootIndexOnInorder = find(inorder.begin() + inStart, inorder.begin() + inEnd, rootValue) - inorder.begin();
        
        TreeNode* root = new TreeNode(rootValue);
        root->left = buildTreeHelper(
            preorder, preStart + 1, preStart + rootIndexOnInorder - inStart,
            inorder, inStart, rootIndexOnInorder - 1 
        );
        
        root->right = buildTreeHelper(
            preorder, preStart + rootIndexOnInorder - inStart + 1, preEnd,
            inorder, rootIndexOnInorder + 1, inEnd
        );
        
        return root;
    }
};