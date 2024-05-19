//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    void allPermute(vector<int> &arr, vector<vector<int>> &ansArr, int idx) {
        if(idx>=arr.size()) {
            ansArr.push_back(arr);
            return;
        }
        for(int i=idx; i<arr.size(); i++) {
            swap(arr[idx],arr[i]);
            allPermute(arr,ansArr,idx+1);
            swap(arr[idx],arr[i]);
        }
    }
public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<vector<int>> ansArr;
        allPermute(arr,ansArr,0);
        sort(ansArr.begin(),ansArr.end());
        ansArr.erase(unique(ansArr.begin(),ansArr.end()),ansArr.end());
        return ansArr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends