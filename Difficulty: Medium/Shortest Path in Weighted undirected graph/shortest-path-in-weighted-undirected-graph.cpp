
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Step 1: Create an adjacency list where each node stores a pair of (neighbour, weight)
        vector<vector<pair<int, int>>> adjList(n + 1);
        for (auto it : edges) {
            adjList[it[0]].push_back({it[1], it[2]}); // Undirected edge
            adjList[it[1]].push_back({it[0], it[2]});
        }
        // Step 2: Set to pick the next node with the shortest distance
        set<pair<int, int>> st;
        // Push the source node (1) with distance 0
        st.insert({0, 1});
        // Step 3: Distance array to store shortest distance from source to every node
        vector<int> dist(n + 1, INT_MAX);
        // Step 4: Parent array to reconstruct the shortest path later
        vector<int> parent(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;  // Initially, every node is its own parent
        }
        dist[1] = 0;  // Distance to the source node is 0
        // Step 5: Dijkstra’s Algorithm main loop
        while (!st.empty()) {
            auto first = *(st.begin());
            int wt = first.first;   // Current distance from source
            int node = first.second;
            st.erase(first);
            // Traverse through all adjacent nodes
            for (auto nbr : adjList[node]) {
                int currWt = nbr.second;    // Weight of the edge to neighbour
                int nbrNode = nbr.first;
                // If a shorter path is found to neighbour
                if (wt + currWt < dist[nbrNode]) {
                    if(dist[nbrNode] != INT_MAX) {
                        st.erase({dist[nbrNode], nbrNode});
                    }
                    dist[nbrNode] = wt + currWt;   // Update distance
                    st.insert({dist[nbrNode], nbrNode});
                    parent[nbrNode] = node;  // Store the parent for path reconstruction
                }
            }
        }
        // If no path to node n, return -1
        if (dist[n] == INT_MAX) return {-1};
        // Step 6: Reconstruct the shortest path from node n to 1 using the parent array
        vector<int> path;
        int node = n;
        // Traverse the parent chain until we reach the source
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);         // Add the source node
        path.push_back(dist[n]);   // Finally, push the shortest distance as the last element

        // The path is currently from destination to source, so reverse it
        reverse(path.begin(), path.end());
        return path;
    }
};
