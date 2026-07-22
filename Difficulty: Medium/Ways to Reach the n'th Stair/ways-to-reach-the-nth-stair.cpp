class Solution {
    // Memorization : T.C: O(n), S.C: O(2*n) : Top-Down Approach
    int countWaysHelper(int n, vector<int>& dp) {
        if(n==1 || n==0) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = countWaysHelper(n-1, dp) + countWaysHelper(n-2, dp); 
    } 
    
  public:
    int countWays(int n) {
        // code here
        vector<int> dp(n+1, -1);
        return countWaysHelper(n, dp);
    }
};
