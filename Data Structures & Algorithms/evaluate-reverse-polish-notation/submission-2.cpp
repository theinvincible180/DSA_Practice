class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();

        stack<int> st;
        for(int i = 0 ; i < n ; i++) {
            if(tokens[i] == "+") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();

                st.push(num1+num2);
            }
            else if(tokens[i] == "-"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();

                st.push(num2-num1);
            }
            else if(tokens[i] == "*"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();

                st.push(num1*num2);
            }
            else if(tokens[i] == "/"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();

                st.push(num2/num1);
            }
            else{
                int x = stoi(tokens[i]);
                st.push(x);
            }
        }

        return st.top();
    }
};
