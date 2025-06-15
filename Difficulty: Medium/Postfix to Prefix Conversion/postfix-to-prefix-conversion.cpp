// User function Template for C++

class Solution {
  public:
    string postToPre(string exp) {
        // Write your code here
        stack<string> st;
        for(int i=0; i<exp.size(); i++) {
            if(isalnum(exp[i])) st.push(string(1,exp[i]));
            else {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                string currOp = exp[i]+op2+op1;
                st.push(currOp);
            }
        }
        return st.top();
    }
};