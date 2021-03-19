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
    ListNode* reverseList(ListNode* head) {
        stack<int> st;
        
        ListNode* cur = head;
        while(cur != nullptr){
            st.push(cur->val);
            cur = cur->next;
        }
                
        ListNode* dummyHead = new ListNode(-1);
        cur = dummyHead;
        while(!st.empty()){
            cur->next = new ListNode(st.top());
            st.pop();
            cur = cur->next;
        }
        
        return dummyHead->next;
    }
};