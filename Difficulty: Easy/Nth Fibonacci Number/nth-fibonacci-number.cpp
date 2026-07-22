// Memorization : Top-Down Approach
class Solution {
  private:
    int nthFibonacciHelper(int n, vector<int>& dp) {
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = nthFibonacciHelper(n-1, dp) + nthFibonacciHelper(n-2, dp);
    }
  public:
    int nthFibonacci(int n) {
        // code here
        vector<int> dp(n+1, -1);
        return nthFibonacciHelper(n, dp);
    }
};
