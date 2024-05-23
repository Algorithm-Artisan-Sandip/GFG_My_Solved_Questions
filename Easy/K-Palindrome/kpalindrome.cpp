//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int kPalindrome(string s, int n, int k)
    {
        // code here
    vector<int>cur(n+1,0),ahead(n+1,0);
    for(int x=n-1;x>=0;x--){
        for(int y=n-1;y>=0;y--) 
             cur[y]= max({ahead[y],cur[y+1],(s[x]==s[n-y-1])?1+ahead[y+1]:0}); 
        ahead=cur;
    }  
    return n-cur[0]<=k;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends