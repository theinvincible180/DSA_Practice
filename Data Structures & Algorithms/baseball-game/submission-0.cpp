class Solution {
public:
    int calPoints(vector<string>& op) {
        int n = op.size();
        stack<int> st;

        for(int i = 0 ; i < n ; i++){
            if(op[i] == "+"){
                int first = st.top();
                st.pop();
                int second = st.top();
                int newScore = first + second;
                st.push(first);
                st.push(newScore);
            }
            else if(op[i] == "C"){
                st.pop();
            }
            else if(op[i] == "D"){
                int first = st.top();
                // st.push(first);
                st.push(first*2);
            }
            else{
                int num = stoi(op[i]);
                st.push(num);
            }
        }

        int sum = 0;
        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};