//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> rearrangeQueue(queue<int> &q) {
        int size = q.size();
        int halfSize = size / 2;
        
        stack<int> dummy;
        for (int i = 0; i < halfSize; ++i) {
            dummy.push(q.front());
            q.pop();
        }
        stack<int> first;
        while(!dummy.empty()) {
            first.push(dummy.top());
            dummy.pop();
        }
        
        stack<int> dummy1;
        for (int i = 0; i < halfSize; ++i) {
            dummy1.push(q.front());
            q.pop();
        }
        stack<int> second;
        while(!dummy1.empty()) {
            second.push(dummy1.top());
            dummy1.pop();
        }
        
        // Interleave elements back into the queue
        while (!first.empty()) {
            q.push(first.top());
            first.pop();
            q.push(second.top());
            second.pop();
        }

        vector<int> arr;
        while (!q.empty()) {
            arr.push_back(q.front());
            q.pop();
        }
        return arr;
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends