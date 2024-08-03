//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int fib(int n){
        //code here
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        int prev1 = 0;
        int prev2 = 1;
        int curr;
        for(int i=2; i<=n; i++) {
            curr = (prev1 + prev2)%10;
            prev1 = prev2;
            prev2 = curr;
        }
        
        return curr;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.fib(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends