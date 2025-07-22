// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Step 1: Initialize the distance matrix
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        // Step 2: Set distances based on the given edges (undirected graph)
        for(auto it : edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        // Step 3: Distance from a node to itself is 0
        for(int i = 0; i < n; i++) dist[i][i] = 0;
        // Step 4: Floyd-Warshall algorithm to compute all-pairs shortest paths
        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                // If there is no path from i to via, skip
                if(dist[i][via] == INT_MAX) continue;
                for(int j = 0; j < n; j++) {
                    // If there is no path from via to j, skip
                    if(dist[via][j] == INT_MAX) continue;
                    // Update the shortest path from i to j via 'via'
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
        // Step 5: Find the city with the smallest number of reachable cities
        // within the distance threshold. In case of a tie, pick the greatest index.
        int cityCnt = n; // Initialize with maximum possible
        int cityNo = -1; // City number to return
        for(int city = 0; city < n; city++) {
            int cnt = 0;
            for(int adjCity = 0; adjCity < n; adjCity++) {
                if(dist[city][adjCity] <= distanceThreshold) {
                    cnt++;
                }
            }
            // Update if fewer cities are reachable or same count but higher city number
            if(cnt <= cityCnt) {
                cityCnt = cnt;
                cityNo = city;
            }
        }
        // Step 6: Return the city with the smallest reachable count and highest index
        return cityNo;
    }
};
