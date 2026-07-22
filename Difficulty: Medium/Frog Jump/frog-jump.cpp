// Memorization : 
class Solution {
    int minCostHelper(vector<int>& height, int n, vector<int>& dp) {
        if(n == 0) return 0;
        if(n == 1) return abs(height[1] - height[0]);
        if(dp[n] != -1) return dp[n];
        int leftRecursion = minCostHelper(height, n-1, dp) + abs(height[n]-height[n-1]);
        int rightRecursion = minCostHelper(height, n-2, dp) + abs(height[n]-height[n-2]);
        return dp[n] = min(leftRecursion, rightRecursion);
    }
  public:
    int minCost(vector<int>& height) {
        // Code here
        int size = height.size();
        vector<int> dp(size, -1);
        return minCostHelper(height, size-1, dp);
    }
};

