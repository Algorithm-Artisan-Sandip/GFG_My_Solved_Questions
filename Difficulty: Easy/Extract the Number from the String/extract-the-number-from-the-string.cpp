//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string s) {

        // code here
        long long val=-1;
        string ans="";
        bool contain_9=false;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='9') {
                contain_9=true;
                ans="";
            }
            if(s[i]==' '){
                contain_9=false;
                if(ans != ""){
                    long long temp=stoll(ans);
                    val=max(val,temp);
                    ans="";
                }
            }
            if(contain_9) continue;
            if(s[i]-'0' <=8 and s[i]-'0' >=0) ans+=s[i];
        }
        
        if(ans != ""){
                    long long temp=stoll(ans);
                    val=max(val,temp);
                    ans="";
                }
        return val;
    }
};


//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends