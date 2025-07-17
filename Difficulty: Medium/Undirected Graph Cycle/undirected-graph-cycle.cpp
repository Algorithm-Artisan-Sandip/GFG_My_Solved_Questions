
class Solution {
private:
    // Helper function to detect a cycle using BFS from a given source node
    bool detectCycleBFS(int src, int V, int vis[], vector<vector<int>>& adjList) {
        vis[src] = 1;  // Mark the source node as visited
        queue<pair<int, int>> q;  // Stores pairs of (currentNode, parentNode)
        q.push({src, -1});  // Initialize queue with source node and no parent (-1)
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            // Traverse all adjacent nodes (neighbors)
            for(auto nbr : adjList[node]) {
                if(!vis[nbr]) {
                    vis[nbr] = 1;  // Mark neighbor as visited
                    q.push({nbr, node});  // Push neighbor with current node as its parent
                }
                // If the neighbor is visited and it's not the parent,
                // then a cycle exists
                else if(parent != nbr) {
                    return true;  // Cycle detected
                }
            }
        }
        return false;  // No cycle found from this component
    }
public:
    // Main function to check if the undirected graph contains a cycle
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Step 1: Create an adjacency list from the edge list
        vector<vector<int>> adjList(V);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);  // Since the graph is undirected
        }
        int vis[V] = {0};  // Visited array initialized to 0 (unvisited)
        // Step 2: Check each component of the graph
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                // If the component has a cycle, return true
                if(detectCycleBFS(i, V, vis, adjList)) {
                    return true;
                }
            }
        }
        return false;  // No cycles found in any component
    }
};
