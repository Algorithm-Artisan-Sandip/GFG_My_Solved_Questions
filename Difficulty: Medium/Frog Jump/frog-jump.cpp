class Solution {
  private:
  // Brute DP Solution : Memorization : T.C: O(n), S.C: O(2*n) : Top-Down Approach
  int findMinCost(int n, vector<int>& height, vector<int>& dp) {
        if(n==0) return 0;
        if(dp[n] != -1) return dp[n];
        int left = findMinCost(n-1, height, dp) + abs(height[n]-height[n-1]);
        int right = INT_MAX;
        if(n>1) right = findMinCost(n-2, height, dp) + abs(height[n]-height[n-2]);
        return dp[n] = min(left, right);
    }
    
  // Pure recursive solution : T.C: O(2^n), S.C: O(n)
    // int findMinCost(int n, vector<int>& height) {
    //     if(n==0) return 0;
    //     int left = findMinCost(n-1, height) + abs(height[n]-height[n-1]);
    //     int right = INT_MAX;
    //     if(n>1) right = findMinCost(n-2, height) + abs(height[n]-height[n-2]);
    //     return min(left, right);
    // }
    
  public:
    int minCost(vector<int>& height) {
        // Code here
        int size = height.size();
        // Pure Recursive Solution : 
        // int ans = findMinCost(size-1, height);
        
        // Brute DP : Memorization 
        vector<int> dp(size+1, -1);
        int ans = findMinCost(size-1, height, dp);
        
        return ans;
    }
};