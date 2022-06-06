// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* nodeA = headA;
        ListNode* nodeB = headB;
        
        int lenA = 1;
        while(nodeA != nullptr) {
            lenA++;
            nodeA = nodeA->next;
        }
        
        int lenB = 1;
        while(nodeB != nullptr) {
            lenB++;
            nodeB = nodeB->next;
        }
        
        nodeA = headA;
        nodeB = headB;
        int size = lenA + lenB;
        while(size--) {
            if (nodeA == nodeB) {
                return nodeA;
            }
            
            nodeA = nodeA->next == nullptr ? headB : nodeA->next;
            nodeB = nodeB->next == nullptr ? headA : nodeB->next;
        }
        
        return nullptr;
    }
};