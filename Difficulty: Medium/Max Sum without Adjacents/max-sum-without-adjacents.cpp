// User function template for C++
class Solution {
  private:
    // Pure Recursive Solution : T.C: O(2^n), S.C: O(n) : 
    // int findMaxSumHelper(vector<int>& arr, int n) {
    //     if(n==0) return arr[0];
    //     if(n<0) return 0;
    //     int first = arr[n] + findMaxSumHelper(arr, n-2);
    //     int second = 0 + findMaxSumHelper(arr, n-1);
    //     return max(first, second);
    // }
    
    // Brute DP : Memorization : T.C: O(n), S.C: O(2*n) : 
    int findMaxSumHelper(vector<int>& arr, int n, vector<int>& dp) {
        if(n==0) return arr[0];
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];
        int first = arr[n] + findMaxSumHelper(arr, n-2, dp); 
        int second = 0 + findMaxSumHelper(arr, n-1, dp); 
        return dp[n] = max(first, second);
    }
    
    // Better DP : Tabulation : T.C: O(n), S.C: O(n) : 
    // int findMaxSumHelper(vector<int>& arr, int n, vector<int>& dp) {
    
    // }
    
  public:
    int findMaxSum(vector<int>& arr) {
        // for pure recursive solution : 
        // int sum = findMaxSumHelper(arr, arr.size());
        
        // for Memorization : 
        vector<int> dp(arr.size() + 1, -1);
        int sum = findMaxSumHelper(arr, arr.size()-1, dp);
        return sum;
    }
};