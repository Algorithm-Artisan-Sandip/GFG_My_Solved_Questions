//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int KthMissingElement(vector<int> &arr, int &k) {
        int cnt = arr[0];
        int temp = 0;
        for(int i=1; i<arr.size(); i++) {
            if(arr[i] == arr[i-1]) continue;
            cnt++;
            while(arr[i] != cnt) {
                temp++;
                if(temp == k) return cnt;
                cnt++;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.KthMissingElement(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends