// User function Template for C++

class Solution {
  public:
    string preToInfix(string exp) {
        // Write your code here
        stack<string> st;
        for(int i=exp.size()-1; i>=0; i--) {
            if(isalnum(exp[i])) st.push(string(1,exp[i]));
            else {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                string currOp = "("+op1+exp[i]+op2+")";
                st.push(currOp);
            }
        }
        return st.top();
    }
};