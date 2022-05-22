#include <stack>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> st1, st2;
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        
        while(tmp1 != nullptr) {
            st1.push(tmp1);
            tmp1 = tmp1->next;
        }
        
        while(tmp2 != nullptr) {
            st2.push(tmp2);
            tmp2 = tmp2->next;
        }
        
        ListNode* head = nullptr;
        int carry = 0;
        while(!st1.empty() || !st2.empty()) {
            int val = 0;
            if (!st1.empty()) {
                val += st1.top()->val;
                st1.pop();
            }
            
            if (!st2.empty()) {
                val += st2.top()->val;
                st2.pop();
            }
            
            val += carry;
            ListNode* newHead = new ListNode(val % 10);
            carry = val / 10;
            
            newHead->next = head;
            head = newHead;
        }
        
        if (carry) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            head = newHead;
        }
        
        return head;
    }
};