class Solution {
private:
    // Pure recursion (exponential time)
    int recursive(int row, int c1, int c2, const vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        // out‑of‑bounds horizontally
        if (c1 < 0 || c1 >= m || c2 < 0 || c2 >= m)
            return INT_MIN / 2;
        // collect at current row
        int cherries = (c1 == c2)
            ? grid[row][c1]
            : grid[row][c1] + grid[row][c2];
        // if last row, done
        if (row == n - 1)
            return cherries;

        int d[3] = {-1, 0, +1};
        int best = INT_MIN / 2;
        // try all 3×3 next‑row moves
        for (int dx1 : d) {
            for (int dx2 : d) {
                best = max(best,
                    recursive(row + 1, c1 + dx1, c2 + dx2, grid));
            }
        }
        return cherries + best;
    }

    // Top‑down memoization (O(n·m²) time & space)
    int memorization(int row, int c1, int c2, const vector<vector<int>>& grid,
                     vector<vector<vector<int>>>& dp) {
        int n = grid.size(), m = grid[0].size();
        // out‑of‑bounds horizontally
        if (c1 < 0 || c1 >= m || c2 < 0 || c2 >= m)
            return INT_MIN / 2;
        // collect at current row
        int cherries = (c1 == c2) ? grid[row][c1] : grid[row][c1] + grid[row][c2];
        // if last row, done
        if (row == n - 1)
            return cherries;

        // if already computed, return it
        if (dp[row][c1][c2] != -1)
            return dp[row][c1][c2];

        int d[3] = {-1, 0, +1};
        int best = INT_MIN / 2;
        // try all 3×3 next‑row moves
        for (int dx1 : d) {
            for (int dx2 : d) {
                best = max(best,
                    memorization(row + 1, c1 + dx1, c2 + dx2, grid, dp));
            }
        }
        return dp[row][c1][c2] = cherries + best;
    }

public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        // Uncomment to use pure recursion (may TLE for large n,m)
        // return recursive(0, 0, m - 1, grid);

        // Top‑down memoization
        vector<vector<vector<int>>> dp(n,
            vector<vector<int>>(m, vector<int>(m, -1)));
        return memorization(0, 0, m - 1, grid, dp);
    }
};