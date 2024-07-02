//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<long long int> nextSmaller(long long int arr[], long long int n) {
        stack<long long int> st;
        vector<long long int> ans(n);
        st.push(n); // sentinel value for the last element

        for (long long int i = n - 1; i >= 0; i--) {
            while (st.top() != n && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    vector<long long int> previousSmaller(long long int n, long long int a[]) {
        stack<long long int> st;
        vector<long long int> ans(n);
        st.push(-1); // sentinel value for the first element

        for (long long int i = 0; i < n; i++) {
            while (st.top() != -1 && a[st.top()] >= a[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    long long getMaxArea(long long arr[], long long int n) {
        vector<long long int> next = nextSmaller(arr, n);
        vector<long long int> prev = previousSmaller(n, arr);

        long long int maxArea = 0;
        for (long long int i = 0; i < n; i++) {
            long long int width;
            if (next[i] == n) {
                width = n - prev[i] - 1;
            } else {
                width = next[i] - prev[i] - 1;
            }
            long long int length = arr[i];
            long long int area = width * length;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};



//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends