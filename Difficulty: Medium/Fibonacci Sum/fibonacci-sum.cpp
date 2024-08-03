//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    long long int fibSum(long long int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        const int modu = 1000000007;
        long long int prev1 = 0;
        long long int prev2 = 1;
        long long int curr;
        long long int sum = 1;

        for (long long int i = 2; i <= n; ++i) {
            curr = (prev1 + prev2) % modu;
            sum = (sum + curr) % modu;
            prev1 = prev2;
            prev2 = curr;
        }

        return sum;
    }
};



//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.fibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends