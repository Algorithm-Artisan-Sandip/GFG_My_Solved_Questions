// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string> st;
        for(int i=0; i<exp.size(); i++) {
            if(isalnum(exp[i])) st.push(string(1, exp[i]));
            else {
                string op2 = st.top(); st.pop();
                string op1 = st.top(); st.pop();
                string currOp = "(" + op1 + exp[i] + op2 + ")";
                st.push(currOp);
            }
        }
        return st.top();
    }
};