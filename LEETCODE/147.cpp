using namespace std;

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sortedHead = new ListNode(head->val);
        ListNode* target = head->next;

        while(target != nullptr) {
            ListNode* pre = nullptr;
            ListNode* cur = sortedHead;
            
            while(cur != nullptr && (target->val > cur->val)) {
                pre = cur;
                cur = cur->next;
            }
            
            if(pre == nullptr) {
				ListNode* newNode = new ListNode(target->val, sortedHead);
                sortedHead = newNode;
            }
            else if(cur == nullptr) {
                ListNode* newNode = new ListNode(target->val);
                pre->next = newNode;
            }
            else{
				ListNode* newNode = new ListNode(target->val, pre->next);
                pre->next = newNode;
            }
            
            target = target->next;
        }
        
        return sortedHead;
    }
};