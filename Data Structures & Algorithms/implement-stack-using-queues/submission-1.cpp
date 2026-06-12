class MyStack {
public:
    queue<int> qt;
    MyStack() {
    }
    
    void push(int x) {
        qt.push(x);
    }
    
    int pop() {
        int n = qt.size();

        while(n > 1) {
            int num = qt.front();
            qt.pop();
            qt.push(num);
            n--;
        }

        int x = qt.front();
        qt.pop();
        return x;

    }
    
    int top() {
        int n = qt.size();

        while(n > 1) {
            int num = qt.front();
            qt.pop();
            qt.push(num);
            n--;
        }

        int x = qt.front();
        qt.pop();
        qt.push(x);
        return x;
    }
    
    bool empty() {
        return qt.empty();
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