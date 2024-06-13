//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int padovanSequence(int n) {
       int mod = 1000000007;
       int first = 1, second = 1, third = 1,fourth =1;
       for(int i=3;i<=n;i++) {
           fourth = (second%mod+first%mod)%mod;
           first = second;
           second= third;
           third = fourth;
       }
       return fourth;
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
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends