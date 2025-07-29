// User Function Template for C++

class Solution {
private:
    // 1) Pure recursion (exponential time)
    int recursiveDFS(int r, int c, int n, int m, vector<vector<int>>& A) {
        // Horizontal bounds check
        if (c < 0 || c >= m) return INT_MIN / 2;
        // If last row, return cell value
        if (r == n - 1) return A[r][c];
        // Explore three downward moves
        int down      = A[r][c] + recursiveDFS(r + 1, c,   n, m, A);
        int downLeft  = A[r][c] + recursiveDFS(r + 1, c - 1, n, m, A);
        int downRight = A[r][c] + recursiveDFS(r + 1, c + 1, n, m, A);
        return max({down, downLeft, downRight});
    }
    
    // 2) Memoization (top-down DP)
    int dfsMemo(int r, int c, int n, int m,
                vector<vector<int>>& A,
                vector<vector<int>>& dp) {
        if (c < 0 || c >= m) return INT_MIN / 2;
        if (r == n - 1) return A[r][c];
        if (dp[r][c] != INT_MIN) return dp[r][c];
        int down      = A[r][c] + dfsMemo(r + 1, c,   n, m, A, dp);
        int downLeft  = A[r][c] + dfsMemo(r + 1, c - 1, n, m, A, dp);
        int downRight = A[r][c] + dfsMemo(r + 1, c + 1, n, m, A, dp);
        return dp[r][c] = max({down, downLeft, downRight});
    }
    
    // 3) Tabulation (bottom-up DP)
    int tabulation(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        // Initialize first row
        for (int j = 0; j < m; ++j) dp[0][j] = A[0][j];
        // Build downwards
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int best = dp[i-1][j];
                if (j > 0)       best = max(best, dp[i-1][j-1]);
                if (j + 1 < m)   best = max(best, dp[i-1][j+1]);
                dp[i][j] = A[i][j] + best;
            }
        }
        // Answer is max in last row
        int ans = INT_MIN;
        for (int j = 0; j < m; ++j)
            ans = max(ans, dp[n-1][j]);
        return ans;
    }
    
    int spaceOptimization(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<int> prev(m, 0);
        for (int j = 0; j < m; ++j) prev[j] = A[0][j];
        // Build downwards
        for (int i = 1; i < n; ++i) {
            vector<int> curr(m, 0);
            for (int j = 0; j < m; ++j) {
                int best = prev[j];
                if (j > 0)       best = max(best, prev[j-1]);
                if (j + 1 < m)   best = max(best, prev[j+1]);
                curr[j] = A[i][j] + best;
            }
            prev = curr;
        }
        // Answer is max in last row
        int ans = INT_MIN;
        for (int j = 0; j < m; ++j)
            ans = max(ans, prev[j]);
        return ans;
    }
    
public : 
    int maximumPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        // 1) Pure recursion:
        // int res = INT_MIN;
        // for (int j = 0; j < m; ++j)
        //     res = max(res, recursiveDFS(0, j, n, m, matrix));
        // return res;

        // 2) Memoization:
        // vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        // int res = INT_MIN;
        // for (int j = 0; j < m; ++j)
        //     res = max(res, dfsMemo(0, j, n, m, matrix, dp));
        // return res;

        // 3) Tabulation (no extra outer loop needed):
        return tabulation(matrix);
        
        // Space Optimization : 
        // return spaceOptimization(matrix);
    }
};
