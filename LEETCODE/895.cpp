#include <unordered_map>
#include <stack>
#include <algorithm>

using namespace std;

class FreqStack {
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> freqStack;
    int maxFreq;
    
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        freqStack[freq[val]].push(val);
        maxFreq = max(maxFreq, freq[val]);
    }
    
    int pop() {
        int ret = freqStack[maxFreq].top();
        freq[ret]--;
        freqStack[maxFreq].pop();
        
        if (freqStack[maxFreq].empty()) {
            maxFreq--;
        }
        
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */