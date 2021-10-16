// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* mergeSort(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode* front;
        ListNode* rear;
        split(head, &front, &rear);
        
        front = mergeSort(front);
        rear = mergeSort(rear);
        
        return mergeArea(front, rear);
    }

    void split(ListNode* head, ListNode** front, ListNode** rear) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast != nullptr) {
            fast = fast->next;
            
            if(fast != nullptr) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        
        *front = head;

        *rear = slow->next;
        slow->next = nullptr;
    }
    
    ListNode* mergeArea(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(-1); // dummy
        ListNode* result = dummy;
        
        while(left != nullptr && right != nullptr) {
            if(left->val < right->val) {
                result->next = left;
                
				result = result->next;
				left = left->next;
            }
            else {
                result->next = right;

				result = result->next;
                right = right->next;
            }
        }
        
        if(left != nullptr) result->next = left;
        else if(right != nullptr) result->next = right;
        
        result = dummy->next;
        delete dummy;
        
        return result;
    }
    
public:
    ListNode* sortList(ListNode* head) {
		return mergeSort(head);
    }
};