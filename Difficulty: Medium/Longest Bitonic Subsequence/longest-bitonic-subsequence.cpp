class Solution {
  public:
    int longestBitonicSequence(int n, vector<int>& arr) {
        // BASE CASE: An empty array cannot form any subsequence.
        if (n == 0) return 0;

        // ==========================================
        // STEP 1: COMPUTE LONGEST INCREASING SUBSEQUENCE (LIS)
        // ==========================================
        // LIS_dp[i] will store the length of the LIS that ends exactly at index i.
        // Every single element is an increasing subsequence of length 1 by default.
        vector<int> LIS_dp(n, 1);  
        
        for(int i = 0; i < n; i++) {
            // Look back at all elements before index i
            for(int prev = 0; prev < i; prev++) {
                // If the previous element is smaller, it can safely extend the sequence.
                // We update LIS_dp[i] only if this path yields a strictly longer sequence.
                if(arr[prev] < arr[i] && LIS_dp[i] < LIS_dp[prev] + 1) {
                    LIS_dp[i] = LIS_dp[prev] + 1;
                }
            }
        }
    
        // ==========================================
        // STEP 2: COMPUTE LONGEST DECREASING SUBSEQUENCE (LDS)
        // ==========================================
        // LDS_dp[i] will store the length of the LDS that starts exactly at index i.
        // Every single element is a decreasing subsequence of length 1 by default.
        vector<int> LDS_dp(n, 1);  
        
        // Loop backwards from right to left
        for(int i = n-1; i >= 0; i--) {
            // Look forward at all elements after index i
            for(int prev = n-1; prev > i; prev--) {
                // If the future element is smaller, it continues the downward trend.
                // We update LDS_dp[i] only if this path yields a strictly longer sequence.
                if(arr[prev] < arr[i] && LDS_dp[i] < LDS_dp[prev] + 1) {
                    LDS_dp[i] = LDS_dp[prev] + 1;
                }
            }
        }
        
        // ==========================================
        // STEP 3: COMBINE LIS AND LDS TO FIND MAXIMUM BITONIC LENGTH
        // ==========================================
        int maxLen = 0;
        
        // Treat every index i as the potential "peak" or "turning point" of the bitonic curve
        for(int i = 0; i < n; i++) {
            // CONSTRAINT: The problem requires a true bitonic sequence containing 
            // BOTH a strictly increasing part and a strictly decreasing part.
            // If LIS_dp[i] == 1 or LDS_dp[i] == 1, it means there is no actual slope on one side.
            if (LIS_dp[i] > 1 && LDS_dp[i] > 1) {
                // Formula: (Length going up to i) + (Length going down from i) - 1
                // We subtract 1 because the peak element at index i is counted in both LIS and LDS.
                maxLen = max(maxLen, LIS_dp[i] + LDS_dp[i] - 1);
            }
        }
        
        return maxLen;
    }
};
