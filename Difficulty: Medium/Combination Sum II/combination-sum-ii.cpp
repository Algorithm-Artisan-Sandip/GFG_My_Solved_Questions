//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  private:
    void findCombSum(int idx, int target, int n, vector<int> ans, set<vector<int>>& finalAns, vector<int> arr) {
        if(target == 0) {
            finalAns.insert(ans);
            return;
        }
        for(int i=idx; i<n; i++) {
            if(i>idx && arr[i] == arr[i-1]) continue;
            if(target < arr[i]) break;
            ans.push_back(arr[i]);
            findCombSum(i+1, target-arr[i], n, ans, finalAns, arr);
            ans.pop_back();
        }
    }
  public:
    // Function to find all combinations of elements
    // in array arr that sum to target.
    vector<vector<int>> uniqueCombinations(vector<int> &arr, int target) {
        // Your code here
        sort(arr.begin(), arr.end());
        vector<int> ans;
        set<vector<int>> finalAns;
        findCombSum(0, target, arr.size(), ans, finalAns, arr);
        vector<vector<int>> combSum(finalAns.begin(), finalAns.end());
        return combSum;
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
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        vector<vector<int>> ans = ob.uniqueCombinations(arr, sum);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            for (int i = 0; i < ans.size(); i++) {
                sort(ans[i].begin(), ans[i].end());
            }
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends