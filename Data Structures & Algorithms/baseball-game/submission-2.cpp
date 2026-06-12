class Solution {
public:
    int calPoints(vector<string>& score) {
        stack<int> st;
        int n = score.size();

        for(int i = 0 ; i < n ; i++) {
            if(score[i] == "+"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();

                // st.push(num2);
                st.push(num1);
                st.push(num1+num2);
            }
            else if(score[i] == "C") st.pop();
            else if(score[i] == "D"){
                int num = st.top();
                st.push(2*num);
            }
            else {
                int num = stoi(score[i]);
                st.push(num);
            }
        }

        int total = 0;
        while(!st.empty()) {
            total += st.top();
            st.pop();
        }

        return total;
    }
};