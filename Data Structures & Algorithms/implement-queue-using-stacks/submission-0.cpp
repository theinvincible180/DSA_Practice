class MyQueue {
public:
    stack<int> st;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        stack<int> temp;
        while(st.size() > 1) {
            int num = st.top();
            st.pop();
            temp.push(num);
        }

        int ans = st.top();

        st.pop();

        while(!temp.empty()) {
            int num = temp.top();
            temp.pop();

            st.push(num);
        }

        return ans;
    }
    
    int peek() {
        stack<int> temp;
        while(st.size() > 1) {
            int num = st.top();
            st.pop();
            temp.push(num);
        }

        int ans = st.top();

        // st.pop();

        while(!temp.empty()) {
            int num = temp.top();
            temp.pop();

            st.push(num);
        }

        return ans;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */