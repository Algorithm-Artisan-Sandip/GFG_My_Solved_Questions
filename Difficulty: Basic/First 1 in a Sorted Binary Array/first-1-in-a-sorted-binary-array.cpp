//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int firstIndex(vector<int> &arr) {
        // Your code goes here
        auto idx = lower_bound(arr.begin(), arr.end(), 1);
        if(idx == arr.end() || *idx != 1) return -1;
        
        int ans = idx - arr.begin();
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.firstIndex(arr) << endl;
    }
}
// } Driver Code Ends