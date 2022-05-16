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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> answer;
        helper(answer, root, 0);
        
        return answer;
    }

private:
    void helper(vector<vector<int>>& answer, Node* node, int level) {
        if (node == nullptr) 
            return;
        
        if (answer.size() <= level) 
            answer.push_back(vector<int>(0));
        
        answer[level].push_back(node->val);
        
        for(Node* next : node->children) {
            helper(answer, next, level + 1);
        }
    }
};