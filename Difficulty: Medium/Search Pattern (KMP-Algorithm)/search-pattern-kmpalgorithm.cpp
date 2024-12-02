//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    vector<int> findLPS(string str) {
        int n = str.size();
        vector<int> pi(n, 0);
        
        for(int i=1; i<n; i++) {
            int j = pi[i-1];
            
            while(j>0 && str[i] != str[j]) j = pi[j-1];
            
            if(str[i] == str[j]) j++;
            
            pi[i] = j;
        }
        return pi;
    }
  public:
    vector<int> search(string& pat, string& txt) {
        // code here
        vector<int> ans;
        
        string str = pat + "&" + txt;
        vector<int> lps = findLPS(str);
        
        int n = txt.size(), m = pat.size();
        
        for(int i=m+1; i<str.size(); i++) {
            if(lps[i] == m) ans.push_back(i-2*m);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends