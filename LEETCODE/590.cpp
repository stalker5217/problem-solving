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
    vector<int> postorder(Node* root) {
        vector<int> order;
        
        if (root != nullptr) {
            helper(root, order);
        }
        
        return order;
    }
    
    void helper(Node* node, vector<int> & order) {
        for (auto child : node->children) {
            helper(child, order);
        }
        
        order.push_back(node->val);
    }
};