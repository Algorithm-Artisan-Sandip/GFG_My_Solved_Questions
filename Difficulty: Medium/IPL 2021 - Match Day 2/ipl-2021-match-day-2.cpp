//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void findAns(vector<int>nums, int n, int k, vector<int>& ans) {
        deque<int> dq;
        for(int i=0; i<k; i++) {
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        for(int i = k; i<n; i++) {
            //storing the answer :
            ans.push_back(nums[dq.front()]);
            
            // removal : 
            // handling out of bound cases :
            if(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            // removing the smaller elements than the current element :
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
    }
    
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> ans;
        findAns(arr,n,k,ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends