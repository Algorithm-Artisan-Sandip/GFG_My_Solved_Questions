class Solution {
  private:
  // Pure Recursive Solution : T.C: O(3^n), S.C: O(n) : 
    // int findAns(vector<vector<int>>& arr, int idx, int taken) {
    //     if (idx == 0) {
    //         int maxPts = INT_MIN;
    //         for (int task = 0; task < 3; task++) {
    //             if (task != taken) {
    //                 maxPts = max(maxPts, arr[0][task]);
    //             }
    //         }
    //         return maxPts;
    //     }
    //     int maxPoints = INT_MIN;
    //     for(int task=0; task<3; task++) {
    //         if(task!=taken) {
    //             maxPoints = max(maxPoints, arr[idx][task] + findAns(arr, idx-1, task));
    //         }
    //     }
    //     return maxPoints;
    // }
    
  // Brute DP :  Memorization : T.C: O(n), S.C: O(2*n) : 
    int findAns(vector<vector<int>>& arr, int idx, int taken, vector<vector<int>>& dp) {
        if (idx == 0) {
            int maxPts = INT_MIN;
            for (int task = 0; task < 3; task++) {
                if (task != taken) {
                    maxPts = max(maxPts, arr[0][task]);
                }
            }
            return maxPts;
        }
        if (dp[idx][taken] != -1) return dp[idx][taken];
        int maxPoints = INT_MIN;
        for(int task=0; task<3; task++) {
            if(task!=taken) {
                maxPoints = max(maxPoints, arr[idx][task] + findAns(arr, idx-1, task, dp));
            }
        }
        return dp[idx][taken] = maxPoints;
    }
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // for Pure Recursive Solution : 
        // int n = arr.size();
        // int ans = findAns(arr, n-1, 3);
        // return ans;
        
        // for Memorization and Tabulation : 
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        int ans = findAns(arr, n-1, 3, dp);
        return ans;
    }
};