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
    void reorderList(ListNode* head) {
        ListNode* cur = head;
        stack<ListNode*> st;
        int cnt = 0;
        while(cur != nullptr) {
            cnt++;
            st.push(cur);
            cur = cur->next;
        }
        
        ListNode* dummy = new ListNode();
        cur = dummy;
        ListNode* front = head;
        for(int i = 0 ; i < cnt / 2; i++) {
            cur->next = front;
            cur = front;
            front = front->next;
            
            cur->next = st.top();
            cur = st.top();
            st.pop();
        }
        
        if (cnt % 2 == 1) {
            cur->next = st.top();
            cur = cur->next;
        }
        cur->next = nullptr;
    }
};