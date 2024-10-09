//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMatching(string text, string pat) {
        // Code here
        int i=0; 
        while(i<text.size()) {
            int j=0;
            if(text[i] == pat[j]) {
                int temp = i;
                while(temp < text.size() && j < pat.size()) {
                    if(text[temp] != pat[j])
                        break;
                    temp++; j++;
                }
            }
            if(j == pat.size()) return i;
            i++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string text, pat;
        cin >> text >> pat;
        Solution obj;
        cout << obj.findMatching(text, pat) << endl;
    }
    return 0;
}
// } Driver Code Ends