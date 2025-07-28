class Solution {
  public:
    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        
        // Min-heap: {cost, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0}); // cost : row : col
        
        vector<int> dr = {-1, 0, 1, 0}; // up, right, down, left
        vector<int> dc = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int cost = curr[0];
            int r = curr[1];
            int c = curr[2];

            if (r == n - 1 && c == n - 1) return cost;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < n) {
                    int newCost = cost + grid[nr][nc];
                    if (newCost < dist[nr][nc]) {
                        dist[nr][nc] = newCost;
                        pq.push({newCost, nr, nc});
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};
