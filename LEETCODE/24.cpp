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
    ListNode* swapPairs(ListNode* head) {
        ListNode* prevCur = nullptr;
        ListNode* cur = head;
        
        if (head == nullptr) {
            return head;
        }
        
        if (head->next != nullptr) {
            head = head->next;
        } 
        
        while (true) {
            if (cur == nullptr || cur->next == nullptr) {
                break;
            }
            
            ListNode* front = cur;
            ListNode* rear = cur->next;
            
            front->next = rear->next;
            rear->next = front;
            
            if (prevCur != nullptr) {
                prevCur->next = rear;
            }
            
            prevCur = cur;
            cur = front->next;
        }
        
        return head;
    }
};