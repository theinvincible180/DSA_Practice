class MyCircularQueue {
public:
    vector<int> arr;
    int space = 0;

    MyCircularQueue(int k) {
        space = k;
    }
    
    bool enQueue(int value) {
        if(arr.size() == space) return false;

        arr.push_back(value);
        return true;
    }
    
    bool deQueue() {
        if(arr.size() == 0) return false;

        arr.erase(arr.begin());
        return true;
    }
    
    int Front() {
        if(arr.size() == 0) return -1;

        return arr.front();
    }
    
    int Rear() {
        if(arr.size() == 0) return -1;

        return arr.back();
    }
    
    bool isEmpty() {
        return arr.size() == 0;
    }
    
    bool isFull() {
        return arr.size() == space;
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