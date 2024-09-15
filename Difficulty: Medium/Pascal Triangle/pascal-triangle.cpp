//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long

class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        vector<vector<long long>> ans;
        
        for (int i=0; i<n; i++){
            
            vector<long long> temp;
            for (int j=0; j<=i; j++){
                if (j == 0 || j == i)
                    temp.push_back(1);
                    
                else {
                    long long element = (ans[i-1][j-1]+ans[i-1][j])%1000000007;
                    temp.push_back(element);
                }
            }
            
            ans.push_back(temp);
        }
        
        return ans[n-1];
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends