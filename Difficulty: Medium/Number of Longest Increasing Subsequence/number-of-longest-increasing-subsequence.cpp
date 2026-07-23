class Solution {
  public:
    int numberofLIS(vector<int>& arr) {
        // Code here
        if (arr.empty()) return 0;
        
        int n = arr.size();
        vector<int> dp(n, 1);     // Stores LIS lengths
        vector<int> count(n, 1);  // Stores LIS counts ending at index i
        
        int maxLength = 1;
        
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (arr[prev] < arr[i]) {
                    // Case A: Found a strictly LONGER subsequence than before
                    if (dp[prev] + 1 > dp[i]) {
                        dp[i] = dp[prev] + 1;
                        count[i] = count[prev]; // Inherit the count from the predecessor
                    }
                    // Case B: Found another subsequence of the EXACT SAME max length
                    else if (dp[prev] + 1 == dp[i]) {
                        count[i] += count[prev]; // Add to the existing combinations
                    }
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        
        // Sum up the counts of all subsequences that achieve maxLength
        int totalNumberOfLIS = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxLength) {
                totalNumberOfLIS += count[i];
            }
        }
        
        return totalNumberOfLIS;
    }
};