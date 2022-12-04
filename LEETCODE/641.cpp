class Node {
public:
    int val;
    Node* previous;
    Node* next;
    
    Node(int val)
    : val(val), previous(nullptr), next(nullptr) {}
};

class MyCircularDeque {
private:
    int size;
    int maxSize;
    Node* front;
    Node* last;
    
public:
    MyCircularDeque(int k) 
    : size(0), maxSize(k) {
        front = nullptr;
        last = nullptr;
    }
    
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        
        Node* newFront = new Node(value);
        newFront->next = front;
        
        if (front != nullptr) {
            front->previous = newFront;
        }
        
        front = newFront;
        
        if (size++ == 0) {
            last = front;
        }
        
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        
        Node* newLast = new Node(value);
        newLast->previous = last;
        
        if (last != nullptr) {
            last->next = newLast;
        }
        
        last = newLast;
        
        if (size++ == 0) {
            front = last;
        }
        
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        
        Node* temp = front;
        front = front->next;
                
        if (--size == 0) {
            last = nullptr;
        }
        
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        
        Node* temp = last;
        last = last->previous;
                
        if (--size == 0) {
            front = nullptr;
        }
        
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : front->val;
    }
    
    int getRear() {
        return isEmpty() ? -1 : last->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */