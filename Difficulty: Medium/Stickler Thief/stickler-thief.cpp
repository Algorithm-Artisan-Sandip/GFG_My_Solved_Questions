class Solution {
  private:
  // Pure Recursive Solution : T.C: O(2^n), S.C: O(n) : 
    // int findAns(vector<int>& arr, int n) {
    //     if(n == 0) return arr[0];
    //     if(n<0) return 0;
    //     int take = arr[n] + findAns(arr, n-2);
    //     int notTake = 0 + findAns(arr, n-1);
    //     return max(take, notTake);
    // }
    
  // Pure Recursive Solution : T.C: O(2^n), S.C: O(n) : Top-Down Approach : 
    int findAns(vector<int>& arr, vector<int>& dp, int n) {
        if(n == 0) return arr[0];
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];
        int take = arr[n] + findAns(arr, dp, n-2);
        int notTake = 0 + findAns(arr, dp, n-1);
        return dp[n] = max(take, notTake);
    }
  public:
    int findMaxSum(vector<int>& arr) {
        // For Pure Recursive Solution : 
        // int ans = findAns(arr, arr.size()-1);
        
        // For Memorization and Tabulation : 
        vector<int> dp(arr.size(), -1);
        int ans = findAns(arr, dp, arr.size()-1);
        return ans;
    }
};