// User function Template for C++

class Solution {
  private:
    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<int>>& grid, int dRow[], int dCol[]) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        // Explore all 4 directions
        for(int i = 0; i < 4; i++) {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];
            // Check bounds and proceed only if it's an unvisited land cell
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m 
            && grid[newRow][newCol] == 1 && !vis[newRow][newCol]) {
                dfs(newRow, newCol, vis, grid, dRow, dCol);       
            }
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // Visited matrix to track land cells connected to the border
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // Direction vectors: up, right, down, left
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        // Step 1: Perform DFS for all boundary land cells
        // Traverse first and last row
        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1 && !vis[0][j]) {
                dfs(0, j, vis, grid, dRow, dCol);
            }
            if(grid[n-1][j] == 1 && !vis[n-1][j]) {
                dfs(n-1, j, vis, grid, dRow, dCol);
            }
        }
        // Traverse first and last column
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1 && !vis[i][0]) {
                dfs(i, 0, vis, grid, dRow, dCol);
            }
            if(grid[i][m-1] == 1 && !vis[i][m-1]) {
                dfs(i, m-1, vis, grid, dRow, dCol);
            }
        }
        // Step 2: Count the number of unvisited land cells (enclaves)
        int landCells = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    landCells++;
                }
            }
        }
        return landCells;
    }
};
