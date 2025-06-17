class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        stack<int> st;
        st.push(-1);
        vector<int> ans;
        for(int i=arr.size()-1; i>=0; i--) {
            while(st.top() <= arr[i] && st.top() != -1) {
                st.pop();
            }
            ans.push_back(st.top());
            st.push(arr[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};