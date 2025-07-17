class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int n = image.size();       // Number of rows
        int m = image[0].size();    // Number of columns
        // Visited matrix to track already processed cells
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // Direction arrays for traversing up, right, down, and left
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        // Queue for BFS traversal
        queue<pair<int, int>> q;
        q.push({sr, sc});           // Start from the source pixel
        vis[sr][sc] = 1;            // Mark the source as visited
        int prevColor = image[sr][sc];  // Original color to be replaced
        image[sr][sc] = newColor;       // Change color of the starting pixel
        // Begin BFS
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // Explore all 4 neighboring directions
            for (int k = 0; k < 4; k++) {
                int newRow = row + dRow[k];
                int newCol = col + dCol[k];
                // Check for valid, unvisited cell with the same original color
                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < m &&
                    !vis[newRow][newCol] &&
                    image[newRow][newCol] == prevColor) {
                    vis[newRow][newCol] = 1;               // Mark as visited
                    q.push({newRow, newCol});              // Add to queue
                    image[newRow][newCol] = newColor;      // Change color
                }
            }
        }
        // Return the modified image after flood fill
        return image;
    }
};
