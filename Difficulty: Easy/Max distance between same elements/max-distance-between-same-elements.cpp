//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        unordered_map<int, pair<int, int>> mpp;
        for(int i=0; i<arr.size(); i++) {
            mpp[arr[i]].first = -1;
            mpp[arr[i]].second = -1;
        }
        int ans = 0;
        for(int i=0; i<arr.size(); i++) {
            if(mpp[arr[i]].first == -1) {
                mpp[arr[i]].first = i;
            }
            else {
                mpp[arr[i]].second = i-mpp[arr[i]].first;
                ans = max(ans, mpp[arr[i]].second);
            }
        }
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
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends