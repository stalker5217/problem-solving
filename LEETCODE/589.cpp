#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
    
    void helper(Node* cur, vector<int> & result) {
        if(cur == nullptr) return;
        
        result.push_back(cur->val);
        for(auto child : cur->children) {
            helper(child, result);
        }
    }
};