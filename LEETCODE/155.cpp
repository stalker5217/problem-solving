#include <vector>
#include <algorithm>

using namespace std;

class MinStack {
private:
    vector<int> mStack;
    
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int val) {
        mStack.push_back(val);
    }
    
    void pop() {
        mStack.pop_back();
    }
    
    int top() {
        return mStack[mStack.size() - 1];
    }
    
    int getMin() {
        return *min_element(mStack.begin(), mStack.end());
    }
};