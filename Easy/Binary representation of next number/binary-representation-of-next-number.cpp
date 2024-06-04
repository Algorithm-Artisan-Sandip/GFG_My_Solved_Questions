//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    string binaryNextNumber(string s) {
        int n = s.length();
        int countOne = 0;
        int idxZero = -1;

        // Count the number of '1's and find the rightmost '0'
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++countOne;
            } else {
                idxZero = i;
            }
        }

        string ans = "";

        // If all bits are '1', return '1' followed by '0's
        if (countOne == n) {
            ans += "1";
            for (int i = 0; i < n; ++i) {
                ans += "0";
            }
        } else {
            // Change the rightmost '0' to '1' and set subsequent bits to '0'
            s[idxZero] = '1';
            for (int i = idxZero + 1; i < n; ++i) {
                s[i] = '0';
            }

            // Skip leading '0's in the result
            int i = 0;
            while (i < n && s[i] == '0') ++i;

            // Append the rest of the string to the result
            for (int j = i; j < n; ++j) {
                ans += s[j];
            }
        }

        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends