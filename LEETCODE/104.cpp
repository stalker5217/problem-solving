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
    int answer = 0;
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        
        getAnswer(root, 1);
        return answer;
    }
    
    void getAnswer(TreeNode* node, int height){
        if(node->left == nullptr && node->right == nullptr) answer = answer > height ? answer : height;
        else if(node->left != nullptr && node->right == nullptr) getAnswer(node->left, height+1);
        else if(node->left == nullptr && node->right != nullptr) getAnswer(node->right, height+1);
        else{
            getAnswer(node->left, height+1);
            getAnswer(node->right, height+1);
        }
    }
};