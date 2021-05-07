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
private:
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode* mergeHead = new ListNode(-1); // dummy node
        ListNode* mergeCur = mergeHead;
        while(a && b){
            if(a->val < b->val){
                mergeCur->next = a;
                a = a->next;
            }
            else{
                mergeCur->next = b;
                b = b->next;
            }
            
            mergeCur = mergeCur->next;
        }
        
        mergeCur->next = a == nullptr ? b : a;
        
        return mergeHead->next;
    }
    
    ListNode* mergeHelper(vector<ListNode*> & lists, int left, int right){
        if(left == right) return lists[left];
        else if(left + 1 == right) return merge(lists[left], lists[right]);
        else{
            int mid = (left + right) / 2;
            ListNode* a  = mergeHelper(lists, left, mid);
            ListNode* b = mergeHelper(lists, mid + 1, right);
            
            return this->merge(a, b);
        }
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        if(lists.size() == 1) return lists[0];
        
        return mergeHelper(lists, 0, lists.size() - 1);
    }
};