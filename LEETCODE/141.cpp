#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> nodeSet;
        
        ListNode* cur = head;
        while(cur != nullptr){
            if(nodeSet.find(cur) != nodeSet.end()) return true;
            
            nodeSet.insert(cur);
            cur = cur->next;
        }
        
        return false;
    }
};