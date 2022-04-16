
// Definition for singly-linked list.
struct ListNode {
	int val;
    ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* front = head;
        ListNode* rear = head;
        
        while(rear != nullptr && rear->next != nullptr) {
            rear = rear->next->next;
            front = front->next;
        }
        
        return front;
    }
};