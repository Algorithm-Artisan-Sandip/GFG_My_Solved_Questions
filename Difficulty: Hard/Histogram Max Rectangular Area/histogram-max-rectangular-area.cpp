// Optimal : T.C: O(n), S.C: O(n)
class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        stack<int> st;
        long long maxArea = 0;
        for(int i=0; i<arr.size(); i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                int poppedEl = arr[st.top()];
                st.pop();
                int nse = i;  // current element is the next smaller element of the popped element
                int pse = (st.empty()) ? -1 : st.top();   // after popping the top element of the stack is the previous smaller element of the popped element
                maxArea = max(maxArea, 1LL*poppedEl*(nse-pse-1)); // formula for finding the area
            }
            st.push(i);  // pusing the indices in the stack
        }
        // the stack still can have elements whose next smallerr elements are not in the array : 
        while(!st.empty()) {
            int poppedEl = arr[st.top()];
            st.pop();
            int pse = (st.empty()) ? -1 : st.top();
            int nse = arr.size();
            maxArea = max(maxArea, 1LL*poppedEl*(nse-pse-1));
        }
        return maxArea;
    }
};
