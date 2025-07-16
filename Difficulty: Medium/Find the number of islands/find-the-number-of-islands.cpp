class Solution {
  private:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        vis[row][col] = 1;  // Mark the starting cell as visited
        int n = grid.size();      // Number of rows
        int m = grid[0].size();   // Number of columns
        queue<pair<int,int>> q;   // Queue for BFS traversal
        q.push({row, col});       // Push the starting cell
        while(!q.empty()) {
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();
            // Explore all 8 directions (including diagonals)
            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++) {
                    int newRow = currRow + i;
                    int newCol = currCol + j;
                    // Check bounds, ensure it's land ('L'), and not visited
                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && 
                       grid[newRow][newCol] == 'L' && !vis[newRow][newCol]) {
                        vis[newRow][newCol] = 1;    // Mark as visited
                        q.push({newRow, newCol});   // Add to queue
                    }
                }
            }
        }
    }
  public:
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();          // Number of rows
        int m = grid[0].size();       // Number of columns
        vector<vector<int>> vis(n, vector<int>(m, 0));  // Visited matrix
        int cnt = 0;  // Count of islands
        // Traverse the entire grid
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // If it's unvisited land, start a new BFS
                if(!vis[i][j] && grid[i][j] == 'L') {
                    cnt++;                // Found a new island
                    bfs(i, j, grid, vis); // Visit all its parts
                }
            }
        }
        return cnt;  // Return the total number of islands
    }
};
