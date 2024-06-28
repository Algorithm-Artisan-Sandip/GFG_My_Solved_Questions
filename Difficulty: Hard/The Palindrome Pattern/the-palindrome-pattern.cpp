//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
#include <string>

class Solution {
private:
    bool isPalindrome(const std::vector<int>& arr, int n) {
        for (int i = 0; i < n / 2; i++) {
            if (arr[i] != arr[n - i - 1]) return false;
        }
        return true;
    }

public:
    std::string pattern(const std::vector<std::vector<int>>& arr) {
        int n = arr.size();
        std::string ans = "-1";

        // Check if any row is palindrome
        for (int i = 0; i < n; i++) {
            if (isPalindrome(arr[i], n)) {
                ans = std::to_string(i) + " R";
                return ans;
            }
        }

        // Check if any column is palindrome
        for (int j = 0; j < n; j++) {
            std::vector<int> currCol(n);
            for (int i = 0; i < n; i++) {
                currCol[i] = arr[i][j];
            }
            if (isPalindrome(currCol, n)) {
                ans = std::to_string(j) + " C";
                return ans;
            }
        }

        return ans;
    }
};



//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends