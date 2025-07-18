// User function Template for C++

class Solution {
  private:
   void dfs(int row, int col, vector<vector<int>>& vis, 
             vector<pair<int, int>>& vec, vector<vector<int>>& grid,
             int baseRow, int baseCol, int dRow[], int dCol[]) {
        vis[row][col] = 1;  // Mark current cell as visited
        int n = grid.size();
        int m = grid[0].size();
        // Store the relative position of the current cell w.r.t. the base cell
        vec.push_back({row - baseRow, col - baseCol});
        // Explore all 4 directions (up, right, down, left)
        for(int i = 0; i < 4; i++) {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];
            // Check for valid unvisited land cells
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m
               && grid[newRow][newCol] == 1 && !vis[newRow][newCol]) {
                dfs(newRow, newCol, vis, vec, grid, baseRow, baseCol, dRow, dCol);       
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // Direction arrays: up, right, down, left
        int dRow[] = {-1, 0, +1, 0};
        int dCol[] = {0, +1, 0, -1};
        // Visited matrix to keep track of explored cells
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // Set to store unique island shapes (using relative coordinates)
        set<vector<pair<int, int>>> st;
        // Traverse the entire grid
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // Start DFS for each unvisited land cell
                if(grid[i][j] == 1 && !vis[i][j]) {
                    vector<pair<int, int>> vec; // store the current island's shape
                    dfs(i, j, vis, vec, grid, i, j, dRow, dCol);
                    st.insert(vec); // Insert the shape into the set
                }
            }
        }
        // Number of distinct islands is the size of the set
        return st.size();
    }
};
