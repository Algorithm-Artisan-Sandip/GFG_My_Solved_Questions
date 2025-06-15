// User function Template for C++

class Solution {
  public:
    string preToPost(string exp) {
        stack<string> st;
        for(int i=exp.size()-1; i>=0; i--) {
            if(isalnum(exp[i])) st.push(string(1,exp[i]));
            else {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                string currOp = op1+op2+exp[i];
                st.push(currOp);
            }
        }
        return st.top();
    }
};