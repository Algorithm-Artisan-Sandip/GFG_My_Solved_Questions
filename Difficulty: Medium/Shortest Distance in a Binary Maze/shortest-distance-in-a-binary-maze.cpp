class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid,
                     pair<int, int> source,
                     pair<int, int> destination) {
        int sr = source.first, sc = source.second;
        int dr = destination.first, dc = destination.second;
        int n = grid.size(), m = grid[0].size();

        // 1) If source or destination is blocked, no path
        if (grid[sr][sc] == 0 || grid[dr][dc] == 0)
            return -1;

        // 2) If source equals destination, distance is zero
        if (sr == dr && sc == dc)
            return 0;

        // 3) Direction vectors for Up, Right, Down, Left
        int dRow[] = {-1, 0, +1, 0};
        int dCol[] = {0, +1, 0, -1};

        // 4) Distance matrix initialized to "infinity"
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[sr][sc] = 0;

        // 5) BFS queue storing {distance_so_far, {row, col}}
        queue<pair<int, pair<int,int>>> q;
        q.push({0, {sr, sc}});
        // 6) Perform BFS
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int currDist = front.first;
            int r = front.second.first, c = front.second.second;
            // 7) As soon as we dequeue the destination, that's the shortest path
            if (r == dr && c == dc)
                return currDist;
            // 8) Explore all 4 neighbors
            for (int i = 0; i < 4; i++) {
                int nr = r + dRow[i];
                int nc = c + dCol[i];
                // 9) Check bounds, traversable (==1), and shorter path
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == 1 &&
                    currDist + 1 < dist[nr][nc]) {
                    dist[nr][nc] = currDist + 1;
                    q.push({dist[nr][nc], {nr, nc}});
                }
            }
        }
        // 10) Destination never reached
        return -1;
    }
};
