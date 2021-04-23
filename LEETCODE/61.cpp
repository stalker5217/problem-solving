
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        
        int size = 0;
        ListNode* cur = head;
        ListNode* last = head;
        while(true){
            size++;
            if(cur->next == nullptr){
                last = cur;
                break;
            }
            else cur = cur->next;
        }
        
        k %= size;
        k = (k > 0) ? size - k : 0;
        
        for(int i = 0 ; i < k ; i++){
            ListNode* nextHead = head->next;
            
            head->next = nullptr;
            last->next = head;
            last = head;
            
            head = nextHead;
        }
        
        return head;
    }
};