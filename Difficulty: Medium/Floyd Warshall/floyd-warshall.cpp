// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        const int INF = 1e8;  // Representation of “no direct edge”
        // Consider each node 'via' as an intermediate point
        for (int via = 0; via < n; via++) {
            // For every possible source node 'i'
            for (int i = 0; i < n; i++) {
                // If there’s no path from i to via, skip inner loop
                if (dist[i][via] == INF) 
                    continue;
                // For every possible destination node 'j'
                for (int j = 0; j < n; j++) {
                    // If via cannot reach j, skip
                    if (dist[via][j] == INF) 
                        continue;
                    // Try path i → via → j and relax if shorter
                    int through = dist[i][via] + dist[via][j];
                    if (through < dist[i][j]) {
                        dist[i][j] = through;
                    }
                }
            }
        }
        // dist[][] is now the all-pairs shortest path matrix
    }
};
