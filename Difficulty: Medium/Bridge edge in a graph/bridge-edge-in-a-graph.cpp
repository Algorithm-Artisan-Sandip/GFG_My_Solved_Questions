class Solution {
private:
    int timer;                 // Timer to assign discovery time to each node
    bool isBridgeFound;        // Flag to indicate if the given edge (c, d) is a bridge

    // Tarjan's Algorithm DFS to detect bridge edges
    void dfs(int node, int parent, int c, int d,
             vector<int>& vis, vector<int>& insertTime, vector<int>& lowestTime,
             vector<vector<int>>& adjList) {
        
        vis[node] = 1;  // Mark current node as visited
        insertTime[node] = lowestTime[node] = timer++;  // Set discovery and low time

        for(int nbr : adjList[node]) {
            if(nbr == parent) continue;  // Skip the parent node

            if(!vis[nbr]) {
                // Recur for unvisited neighbors
                dfs(nbr, node, c, d, vis, insertTime, lowestTime, adjList);

                // After visiting, update the low time of the current node
                lowestTime[node] = min(lowestTime[node], lowestTime[nbr]);

                // Check if the edge (node, nbr) is a bridge
                if(lowestTime[nbr] > insertTime[node]) {
                    // If it's the specific edge we're interested in
                    if((node == c && nbr == d) || (node == d && nbr == c)) {
                        isBridgeFound = true;
                    }
                }
            } else {
                // Update the low time if the neighbor is already visited
                lowestTime[node] = min(lowestTime[node], insertTime[nbr]);
            }
        }
    }

public:
    // Function to check whether the edge (c, d) is a bridge
    bool isBridge(int V, vector<vector<int>>& edges, int c, int d) {
        timer = 1;
        isBridgeFound = false;

        // Construct adjacency list from edges
        vector<vector<int>> adjList(V);
        for(auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        // Initialize helper arrays
        vector<int> vis(V, 0);         // Visited array
        vector<int> insertTime(V, 0);  // Discovery time of nodes
        vector<int> lowestTime(V, 0);  // Lowest discovery time reachable

        // Perform DFS for each connected component
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, c, d, vis, insertTime, lowestTime, adjList);
            }
        }

        return isBridgeFound;
    }
};
