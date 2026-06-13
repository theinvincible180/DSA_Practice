class MinStack {
public:
    stack<int> st;
    multiset<int> minVal;
    int mn = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        minVal.insert (val);

        st.push(val);
    }
    
    void pop() {
        int num = st.top();
        st.pop();

        auto it = minVal.find(num);
        if(it != minVal.end()) minVal.erase(it);
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return *(minVal.begin());
    }
};
