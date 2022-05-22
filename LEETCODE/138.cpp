#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> indexMap;
        
        vector<Node*> copyArr;  
        Node* dummy = new Node(-1);
        Node* copyPrev = dummy;
        
        int i = 0;
        Node* cur = head;
        while(cur != nullptr) {
            indexMap[cur] = i++;
                        
            copyPrev->next = new Node(cur->val);
            copyPrev = copyPrev->next;
            copyArr.push_back(copyPrev);
            
            cur = cur->next;
        }
        
        cur = head;
        Node* copyCur = dummy->next;
        while(copyCur != nullptr) {
            if (cur->random != nullptr) {
                copyCur->random = copyArr[indexMap[cur->random]];
            }
            cur = cur->next;
            copyCur = copyCur->next;
        }
        
        return dummy->next;
    }
};