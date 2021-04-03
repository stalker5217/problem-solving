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
    vector<vector<int> > answer;
public:
    vector<vector<int> > pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        getAnswer(root, targetSum, path);
        return answer;
    }
    
    void getAnswer(TreeNode* node, int targetSum, vector<int> & path){
        if(node == nullptr) return;
        
        path.push_back(node->val);
        
        if(node->left == nullptr && node->right == nullptr && targetSum == node->val){
            answer.push_back(path);
        }
        else{
            getAnswer(node->left, targetSum - node->val, path);
            getAnswer(node->right, targetSum - node->val, path);
        }
        
        path.pop_back();
    }
};