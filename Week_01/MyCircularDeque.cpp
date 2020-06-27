class MyCircularDeque {
private:
    
    vector<int> data;

    int size;
public:
    MyCircularDeque() {size=0;}
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (data.size() == size) {
            return false;
        }
        
        data.insert(data.begin(), value);
        return true;
        
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (data.size() == size) {
            return false;
        }
        
        data.push_back(value);
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (data.empty()) {
            return false;
        }
        
        data.erase(data.begin());
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (data.empty()) {
            return false;
        }
        
        data.pop_back();
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (data.empty()) {
            return -1;
        }
        return data.front();
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (data.empty()) {
            return -1;
        }
        return data.back();
        
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return data.empty();
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if (data.size() == size) {
            return true;
        } else {
            return false;
        }
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