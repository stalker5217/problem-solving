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
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* cur = head;
        while(cur != nullptr) {
            arr.push_back(cur->val);
            cur = cur->next;
        }
        
        bool result = true;
        for(int start = 0, end = arr.size() - 1 ; start < end ; start++, end--) {
            if(arr[start] != arr[end]) {
                result = false;
                break;
            }
        }
        
        return result;
    }
};