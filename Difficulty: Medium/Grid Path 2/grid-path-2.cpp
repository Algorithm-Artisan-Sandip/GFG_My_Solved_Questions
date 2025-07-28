class Solution {
private:
    const int MOD = 1e9 + 7;
    // Recursive solution (inefficient for large grids)
    // Explores all paths by moving up and left
    int recursive(int n, int m, const vector<vector<int>> &grid) {
        if (n < 0 || m < 0) return 0;
        if (grid[n][m] == 1) return 0;
        if (n == 0 && m == 0) return 1;

        int up = recursive(n - 1, m, grid) % MOD;
        int left = recursive(n, m - 1, grid) % MOD;
        return (up + left) % MOD;
    }

    // Memoization (top-down DP)
    // Stores results in dp to avoid recomputation
    int memoization(int n, int m, vector<vector<int>> &dp, const vector<vector<int>> &grid) {
        if (n < 0 || m < 0) return 0;
        if (grid[n][m] == 1) return 0;
        if (n == 0 && m == 0) return 1;
        if (dp[n][m] != -1) return dp[n][m];

        int up = memoization(n - 1, m, dp, grid) % MOD;
        int left = memoization(n, m - 1, dp, grid) % MOD;
        return dp[n][m] = (up + left) % MOD;
    }

    // Tabulation (bottom-up DP)
    // Builds the solution from (0,0) to (n,m) using 2D dp table
    int tabulation(int n, int m, const vector<vector<int>> &grid) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = (grid[0][0] == 0) ? 1 : 0;

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                if (i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
        return dp[n][m] % MOD;
    }

    // Space-optimized DP
    // Uses two 1D arrays to track current and previous row results
    int spaceOptimized(int n, int m, const vector<vector<int>> &grid) {
        vector<int> prev(m + 1, 0);
        for (int i = 0; i <= n; ++i) {
            vector<int> curr(m + 1, 0);
            for (int j = 0; j <= m; ++j) {
                if (grid[i][j] == 1) {
                    curr[j] = 0;
                    continue;
                }
                if (i == 0 && j == 0) {
                    curr[j] = 1;
                } else {
                    int up = (i > 0) ? prev[j] : 0;
                    int left = (j > 0) ? curr[j - 1] : 0;
                    curr[j] = (up + left) % MOD;
                }
            }
            prev = curr;
        }
        return prev[m] % MOD;
    }

public:
    // Master function to compute number of unique paths
    // Chooses the optimal implementation (currently space-optimized)
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return 0;

        // Option 1: Recursive (for small inputs only)
        // return recursive(n - 1, m - 1, grid);

        // Option 2: Memoization
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return memoization(n - 1, m - 1, dp, grid);

        // Option 3: Tabulation
        return tabulation(n - 1, m - 1, grid);

        // Option 4: Space Optimized
        // return spaceOptimized(n - 1, m - 1, grid);
    }
};
