//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    long long getCount(int n) {
        if (n == 1) return 10;
        
        vector<vector<int>> adjList = {
            {0, 8},     // neighbors for 0
            {1, 2, 4},  // neighbors for 1
            {2, 1, 3, 5}, // neighbors for 2
            {3, 2, 6},  // neighbors for 3
            {4, 1, 5, 7}, // neighbors for 4
            {5, 2, 4, 6, 8}, // neighbors for 5
            {6, 3, 5, 9}, // neighbors for 6
            {7, 4, 8}, // neighbors for 7
            {8, 5, 7, 9, 0}, // neighbors for 8
            {9, 6, 8}  // neighbors for 9
        };

        vector<vector<long long>> dpTable(n + 1, vector<long long>(10, 0));

        for (int i = 0; i < 10; ++i) {
            dpTable[1][i] = 1;
        }

        for (int length = 2; length <= n; ++length) {
            for (int digit = 0; digit < 10; ++digit) {
                dpTable[length][digit] = 0;
                for (int neighbor : adjList[digit]) {
                    dpTable[length][digit] += dpTable[length - 1][neighbor];
                }
            }
        }

        long long totalCombinations = 0;
        for (int digit = 0; digit < 10; ++digit) {
            totalCombinations += dpTable[n][digit];
        }

        return totalCombinations;
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
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends