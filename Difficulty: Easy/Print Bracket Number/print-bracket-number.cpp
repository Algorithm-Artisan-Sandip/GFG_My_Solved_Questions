//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    vector<int> bracketNumbers(string str) {
        vector<int> result;
        int num = 0;  // This will be used to assign numbers to brackets
        stack<int> s; // Stack to keep track of open brackets
        
        for (char ch : str) {
            if (ch == '(') {
                num++;
                s.push(num);
                result.push_back(num);
            } else if (ch == ')') {
                if (!s.empty()) {
                    result.push_back(s.top());
                    s.pop();
                }
            }
        }
        return result;
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

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends