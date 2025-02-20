//{ Driver Code Starts
#include <bits/stdc++.h>
#include <limits.h>
#include <random>
#include <sstream>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> minAnd2ndMin(vector<int> &arr) {
        int mini = INT_MAX;
        int secMini = INT_MAX;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] < mini) {
                secMini = mini;
                mini = arr[i];
            }
            else if(arr[i] < secMini && arr[i] > mini) {
                secMini = arr[i];
            }
        }
        
        if(mini == INT_MAX || secMini == INT_MAX) {
            return {-1};
        }
        else return {mini, secMini};
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.minAnd2ndMin(arr);
        if (ans[0] == -1)
            cout << -1 << endl;
        else
            cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends