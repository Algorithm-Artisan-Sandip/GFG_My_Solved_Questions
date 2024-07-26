//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class Solution {
//   public:

//     bool kPangram(string str, int k) {
//         // code here
//         map<char,bool> table;
//         int i=0;
//         for(auto ch : str) {
//             table[ch] = true;
//         }
        
//         int count = 0;
//         for(char ch='a'; ch<='z'; ch++) {
//             if(table.find(ch) == table.end()) count++;
//         }
        
//         if(count > k) return false;
//         else return true;
//     }
// };

class Solution {
public:
    bool kPangram(string str, int k) {
        set<char>st;
        int count = 0;
        for(int i=0;i<str.length();i++)
        {
             if(str[i]!=' ' and str[i]!=',' and str[i]!='.'){
             count++;
             st.insert(str[i]);
             }
        }
        
        if(count < 26 ) return false;
        if(st.size()==26)return true;
        if(26 - st.size() <= k) return true;
        return false;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends