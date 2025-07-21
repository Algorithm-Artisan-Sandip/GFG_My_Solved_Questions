
class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>>& heights) {
        // effort[r][c] = minimum over all paths from (0,0) to (r,c)
        //                of the maximum |height difference| along that path
        vector<vector<int>> effort(rows, vector<int>(columns, INT_MAX));
        // Min-heap storing (effort_so_far, (row, col))
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;
        // Start at (0,0) with zero effort
        effort[0][0] = 0;
        pq.push({0, {0, 0}});
        // Direction vectors for Up, Right, Down, Left
        int dRow[4] = {-1, 0, +1, 0};
        int dCol[4] = {0, +1, 0, -1};
        while (!pq.empty()) {
            // 1) Pop the cell with the current smallest “effort so far”
            auto front = pq.top(); 
            pq.pop();
            int currEffort = front.first;
            int r = front.second.first;
            int c = front.second.second;
            // 2) If we reached bottom-right, we have the minimum possible effort
            if (r == rows - 1 && c == columns - 1) 
                return currEffort;
            // 3) Skip stale entries where we already found a better effort
            if (currEffort > effort[r][c]) 
                continue;
            // 4) Explore neighbors
            for (int i = 0; i < 4; ++i) {
                int nr = r + dRow[i];
                int nc = c + dCol[i];
                // 5) Check bounds
                if (nr < 0 || nr >= rows || nc < 0 || nc >= columns) 
                    continue;
                // 6) Compute edge effort = height difference between cells
                int diff = abs(heights[nr][nc] - heights[r][c]);
                // 7) Path effort to neighbor is max of current path’s effort and this edge’s
                int newEffort = max(currEffort, diff);
                // 8) Relax if we can improve the neighbor’s recorded effort
                if (newEffort < effort[nr][nc]) {
                    effort[nr][nc] = newEffort;
                    pq.push({newEffort, {nr, nc}});
                }
            }
        }
        // Should never happen on a non-empty grid, but return 0 as fallback
        return 0;
    }
};
