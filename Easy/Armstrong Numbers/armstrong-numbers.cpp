//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string armstrongNumber(int n){
        int sum = 0;
        int cube;
        int r;
        int m = n;
        while(n){
            r = n%10;
            cube = r*r*r;
            sum += cube;
            n = n/10;
        }
        if(sum == m) return "Yes";
        else return "No";
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends