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
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return selectNode(nums, 0, nums.size() - 1);
    }
    
    TreeNode* selectNode(vector<int>& nums, int start, int end){
        if(start > end) return nullptr;
        
        int mid = (start + end)/2;
        TreeNode* cur = new TreeNode(nums[mid]);
        
        cur->left = selectNode(nums, start, mid - 1);
        cur->right = selectNode(nums, mid + 1, end);
        
        return cur;
    }
};