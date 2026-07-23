class Solution {
  public:
    vector<int> largestSubset(vector<int>& arr) {
        // code here
        if (arr.empty()) return {};

        int n = arr.size();
        
        // 1. Sort in DESCENDING order to naturally prioritize larger values first
        sort(arr.begin(), arr.end(), greater<int>());

        vector<int> dp(n, 1);       // dp[i] stores the LIS size ending at index i
        vector<int> parent(n, -1);   // Tracks predecessors to rebuild the subset
        
        int maxLength = 0;
        int lastIndex = 0;

        // 2. Compute DP array 
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                // Since it is descending, arr[prev] is larger than arr[i]
                if (arr[prev] % arr[i] == 0 && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    parent[i] = prev;
                }
            }
            // Strict '>' keeps the earliest pool of indices (the largest starting numbers)
            if (dp[i] > maxLength) {
                maxLength = dp[i];
                lastIndex = i;
            }
        }

        // 3. Reconstruct the subset backwards using parent links
        vector<int> result;
        int curr = lastIndex;
        while (curr != -1) {
            result.push_back(arr[curr]);
            curr = parent[curr];
        }

        // The backtracking path gives elements from smallest to largest (ascending)
        // because we start at 'lastIndex' (smallest leaf) and follow parents up to the largest root.
        // Therefore, NO REVERSAL IS NEEDED; it is already perfectly sorted in ascending order!
        return result;
    }
};