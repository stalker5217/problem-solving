#include <queue>
#include <algorithm>

using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
    
public:    
    void push(int x) {
        q1.push(x); 
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        
        swap(q1, q2);
    }
    
    int pop() {
        int ret = q2.front();
        q2.pop();
        
        return ret;
    }
    
    int top() {
        return q2.front();
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */