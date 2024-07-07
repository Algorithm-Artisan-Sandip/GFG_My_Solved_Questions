//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        int rem = q.size()-k; // future use
        
        // copy first k elements of the queue in the stack
        stack<int> st;
        while(k--) {
            st.push(q.front());
            q.pop();
        }
        
        // copy the elements of the stack in the queue :
        while(!st.empty()) {
            q.push(st.top());
            st.pop();
        }
        
        // now pop and push first n-k elements of the queue so 
        // that they adhere to the end of the queue in the same relative order : 
        while(rem--) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        
        return q;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends