class StockSpanner {
public:
    stack<int> st;
    stack<int> temp;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 1;
        if(!st.empty()){
            while(!st.empty() && st.top() <= price){
                int num = st.top();
                temp.push(num);
                cnt++;
                st.pop();
            }

            while(!temp.empty()) {
                int x = temp.top();
                temp.pop();
                st.push(x);
            }
        }
        st.push(price);

        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */