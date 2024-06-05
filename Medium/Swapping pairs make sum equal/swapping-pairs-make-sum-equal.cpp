//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Calculate the sum of both arrays
        int sumA = accumulate(a, a + n, 0);
        int sumB = accumulate(b, b + m, 0);
        
        // If the difference is odd, return -1 as it cannot be evenly divided
        if ((sumA - sumB) % 2 != 0) {
            return -1;
        }
        
        int target = (sumA - sumB) / 2;
        
        // Use a set for quick lookup
        unordered_set<int> setB(b, b + m);
        
        // Traverse through array a
        for (int i = 0; i < n; i++) {
            // Check if there exists an element in b that can be swapped with a[i]
            if (setB.find(a[i] - target) != setB.end()) {
                return 1;
            }
        }
        
        // If no such pair is found, return -1
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends