class StockSpanner {
public:
    stack<pair<int, int>> st;
    // stack<int> temp;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 1;
        // if(!st.empty()){
        //     while(!st.empty() && st.top() <= price){
        //         int num = st.top();
        //         temp.push(num);
        //         cnt++;
        //         st.pop();
        //     }

        //     while(!temp.empty()) {
        //         int x = temp.top();
        //         temp.pop();
        //         st.push(x);
        //     }
        // }

        while(!st.empty() && st.top().first <= price){
            cnt += st.top().second;
            st.pop();
        }
        st.push({price, cnt});

        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */