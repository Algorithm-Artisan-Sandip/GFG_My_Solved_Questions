//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool solve(int n, vector<bool> &dp){
        if(n == 2) return true;
        
        if(dp[n]) return dp[n];
        
        bool ans = false;
        for(int i=1;i<n;i++){
            if(n % i == 0){
                ans = ans || !solve(n-i, dp);
            }
        }
        
        return dp[n] = ans;
    }
  
    bool divisorGame(int n) {
        vector<bool> dp(n+1, false);
        return solve(n, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution obj;
        bool ans = obj.divisorGame(n);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends