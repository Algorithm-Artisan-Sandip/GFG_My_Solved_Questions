// User function Template for C++

class Solution {
  private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis,
             vector<int>& checkSafe, vector<int> adj[]) {
        vis[node] = 1;         // Mark node as visited
        pathVis[node] = 1;     // Mark node in the current DFS path
        for (auto nbr : adj[node]) {
            // If the neighbor has not been visited, call DFS on it
            if (!vis[nbr]) {
                if (dfs(nbr, vis, pathVis, checkSafe, adj) == true) {
                    // If a cycle is detected, mark current node as unsafe
                    checkSafe[node] = 0;
                    return true;
                }
            }
            // If neighbor is in the current path, a cycle is found
            else if (pathVis[nbr] == 1) {
                checkSafe[node] = 0;
                return true;
            }
        }
        // Backtrack: remove node from current path
        pathVis[node] = 0;
        checkSafe[node] = 1;  // Mark node as safe
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);        // Marks whether a node has been visited
        vector<int> pathVis(V, 0);    // Marks nodes in the current DFS path
        vector<int> checkSafe(V, 0);// Memoization:1 if node is safe, 0 if unsafe
        vector<int> safeNodes;        // Stores all eventual safe nodes
        // Run DFS for all unvisited nodes
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, pathVis, checkSafe, adj);
            }
        }
        // Collect all safe nodes
        for (int i = 0; i < V; i++) {
            if (checkSafe[i] == 1) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};
