//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int maxConsecutiveCount(vector<int> &arr) {
        int oneCnt=1, zeroCnt=1;
        int ans = 1;
        for(int i=0; i<arr.size()-1; i++) {
            if(arr[i] == 0 && arr[i] == arr[i+1]) {
                zeroCnt++;
                oneCnt = 1;
            }
            else if(arr[i] == 1 && arr[i] == arr[i+1]) {
                oneCnt++;
                zeroCnt = 1;
            }
            else {
                oneCnt = 1;
                zeroCnt = 1;
            }
            ans = max(ans, max(oneCnt, zeroCnt));
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
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.maxConsecutiveCount(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends