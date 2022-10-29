#include <vector>

using namespace std;

class MyCircularQueue {
private:
    vector<int> container;
    int head;
    int rear;
    int size;
    
public:
    MyCircularQueue(int k) 
    : container(k)
    {
        head = 0;
        rear = 0;
        size = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        
        size++;
        container[rear++] = value;
        rear %= container.size();
        
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        
        size--;
        head = (head + 1) % container.size();
        
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        
        return container[head];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        
        return rear == 0 ? container[container.size() - 1] : container[rear - 1];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == container.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */