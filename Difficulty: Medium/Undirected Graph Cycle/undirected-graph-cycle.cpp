
class Solution {
private:
    // Helper function to perform DFS and detect a cycle
    bool detectCycleDFS(int src, int parent, int V, int vis[], 
                        vector<vector<int>>& adjList) {
        vis[src] = 1;  // Mark the current node as visited
        // Explore all adjacent nodes
        for(auto nbr : adjList[src]) {
            if(!vis[nbr]) {
                // If the neighbor is not visited, recurse
                if(detectCycleDFS(nbr, src, V, vis, adjList)) {
                    return true;  // Cycle found in recursion
                }
            }
            // If the neighbor is visited and is not the parent, a cycle exists
            else if(parent != nbr) {
                return true;  // Back edge found → cycle exists
            }
        }
        return false;  // No cycle found in this DFS path
    }
public:
    // Main function to check if an undirected graph contains a cycle
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Step 1: Build the adjacency list
        vector<vector<int>> adjList(V);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);  // Since the graph is undirected
        }
        int vis[V] = {0};  // Visited array initialized to 0 (all unvisited)
        // Step 2: Traverse each disconnected component
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                // If DFS from this node detects a cycle, return true
                if(detectCycleDFS(i, -1, V, vis, adjList)) {
                    return true;
                }
            }
        }
        return false;  // No cycle detected in any component
    }
};
