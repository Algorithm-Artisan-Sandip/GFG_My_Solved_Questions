//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
// class Solution {
//   public:
//     vector<int> removeDuplicate(vector<int>& arr) {
//         // code here
//     }
// };

// Brute Force : Using set : T.C: O(nlogn), S.C: O(n)
class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        // copying the unique ones in a set : 
        unordered_set<int> seen;
        
        int pos = 0;
        for(auto& it : arr) {
            if(seen.find(it) == seen.end()) {
                seen.insert(it);
                arr[pos++] = it;
            }
        }
        
        arr.resize(pos);
        return arr;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.removeDuplicate(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends