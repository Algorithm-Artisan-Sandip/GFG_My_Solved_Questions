//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s) { // Corrected parameter type to string
        const long long int mod = 1e9 + 7;
        int n = s.size();
        long long ans = 0;
        long long int prev = s[0] - '0'; // Corrected data type
        long long int next; // Corrected variable declaration

        ans += prev;
        for (int i = 1; i < n; i++) { // Start loop from index 1
            next = (i + 1) * (s[i] - '0') + 10 * prev; // Corrected formula
            next %= mod;
            ans += next;
            ans %= mod;
            prev = next;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends