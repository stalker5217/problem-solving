
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if (root1 == nullptr && root2 == nullptr) {
            return nullptr;
        } 
        
        int val1 = (root1 == nullptr) ? 0 : root1->val;
        int val2 = (root2 == nullptr) ? 0 : root2->val;
        
        TreeNode* nextLeft1 = (root1 == nullptr) ? nullptr : root1->left;
        TreeNode* nextRight1 = (root1 == nullptr) ? nullptr : root1->right;
        
        TreeNode* nextLeft2 = (root2 == nullptr) ? nullptr : root2->left;
        TreeNode* nextRight2 = (root2 == nullptr) ? nullptr : root2->right;
        
        TreeNode* mergedNode = new TreeNode(val1 + val2);
        mergedNode->left  = mergeTrees(nextLeft1, nextLeft2);
        mergedNode->right = mergeTrees(nextRight1, nextRight2);
        
        return mergedNode;
    }
};