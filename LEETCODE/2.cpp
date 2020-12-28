
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode();
		ListNode* cur = root;

		int pre = 0;
		while(l1 != nullptr || l2 != nullptr){
			int sum = pre;
			
			if(l1 != nullptr){
				sum += l1->val;
				l1 = l1->next;
			}

			if(l2 != nullptr){
				sum += l2->val;
				l2 = l2->next;
			}

			if(sum >= 10){
				pre = 1;
				sum -= 10;
			}
			else pre = 0;

			cur->next = new ListNode(sum);
			cur = cur->next;
		}

		if(pre) cur->next = new ListNode(pre);
		return root->next;
    }
};