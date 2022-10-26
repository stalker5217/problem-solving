#include <vector>
#include <algorithm>

using namespace std;

class CustomStack {
private:
    vector<int> arr;
    const int maxSize;
public:
    CustomStack(int maxSize)
    : maxSize(maxSize) {}
    
    void push(int x) {
        if (arr.size() < maxSize) {
            arr.push_back(x);
        }
    }
    
    int pop() {
        int ret = -1;
        if (!arr.empty()) {
            ret = arr.back();
            arr.pop_back();
        } 
        
        return ret;
    }
    
    void increment(int k, int val) {
        int arrSize = arr.size();
        int length = min(k, arrSize);
        for (int i = 0 ; i < length ; i++) {
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */