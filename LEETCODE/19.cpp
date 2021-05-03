#include <vector>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> arr;
        ListNode* cur = head;
        
        while(cur != nullptr){
            arr.push_back(cur);
            cur = cur->next;
        }
        
        int removeIdx = arr.size() -  n;
        
        if(removeIdx == 0) head = arr[removeIdx]->next;
        else arr[removeIdx-1]->next = arr[removeIdx]->next;
        
        return head;
    }
};