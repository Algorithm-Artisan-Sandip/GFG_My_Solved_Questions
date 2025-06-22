// Optimial : T.C: O(3*n) + O(k), S.C: O(2*n)
class Solution {
  public:
    string removeKdigits(string s, int k) {
        // code here
        stack<char> st;
        for(int i=0; i<s.size(); i++) {
            while(!st.empty() && k>0 && (st.top()-'0')>(s[i]-'0')) {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        // if still k is not zero : 
        while(k--) st.pop();
        // if now the stack is empty : 
        if(st.empty()) return "0";
        // forming the result string : 
        string result = "";
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        // removing the leading zeros which are stored at the last of the result string : 
        while(result.size() && result.back() == '0') result.pop_back();
        // if now the result is a empty string : 
        if(!result.size()) return "0";
        // reversing the result string to get the correct order of the answer string : 
        reverse(result.begin(), result.end());
        return result;
    }
};