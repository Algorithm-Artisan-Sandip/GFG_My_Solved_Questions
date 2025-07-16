class Solution {
  private:
    // Helper function to perform recursive DFS traversal
    void dfsTraversal(int node, vector<int>& dfsAns, int vis[],
                      vector<vector<int>>& adj) {
        vis[node] = 1;  // Mark the current node as visited
        dfsAns.push_back(node); // Add the current node to the DFS result
        // Traverse all the adjacent (neighbor) nodes
        for (auto nbr : adj[node]) {
            // If the neighbor has not been visited, recurse
            if (!vis[nbr])
                dfsTraversal(nbr, dfsAns, vis, adj);
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> dfsAns; // Stores the final DFS traversal order
        int vis[adj.size()] = {0};  // Visited array to track visited nodes
        dfsTraversal(0, dfsAns, vis, adj); // Start DFS from node 0
        return dfsAns;                         
    }
};
