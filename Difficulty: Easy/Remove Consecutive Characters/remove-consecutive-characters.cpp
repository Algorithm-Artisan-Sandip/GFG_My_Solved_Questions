//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removeConsecutiveCharacter(string& s) {
        // code here.
        string str = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i] != s[i+1]) str += s[i];
        }
        return str;
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
        cout << ob.removeConsecutiveCharacter(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends