//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


// } Driver Code Ends
//User function Template for C++

// Approach 1 : Using Count Sort  
class Solution{
    public:
    string countSort(string arr){
        // code here
        int n = arr.size();
        vector<int> freq(26,0);
        for(int i=0; i<n; i++) {
            freq[arr[i]-'a']++;
        }
        
        // modifying the freq array :
        for(int i=1; i<26; i++) {
            freq[i] += freq[i-1];
        }
        
        string op(n,' ');
        for(int i=n-1; i>=0; i--) {
            op[--freq[arr[i]-'a']] = arr[i];
        }
        
        return op;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}

// } Driver Code Ends