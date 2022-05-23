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

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        if (root != nullptr) inOrder(root);
    }
    
    int next() {
        return seq[index++];
    }
    
    bool hasNext() {
        return index < seq.size();
    }

private:
    vector<int> seq;
    int index = 0;
    
    void inOrder(TreeNode* node) {
        if (node->left != nullptr) inOrder(node->left);
        seq.push_back(node->val);
        if (node->right != nullptr) inOrder(node->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */