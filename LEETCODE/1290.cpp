
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
    int getDecimalValue(ListNode* head) {
        int answer = 0;
        ListNode* cur = head;
        while(cur != nullptr) {
            answer <<= 1;
            if (cur->val == 1) {
                answer |= 1;
            }
            cur = cur->next;
        }
        
        return answer;
    }
};