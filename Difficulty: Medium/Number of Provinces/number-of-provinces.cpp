class Solution {
  private:
    void dfs(int node, vector<vector<int>> adj, int vis[], int V) {
        vis[node] = 1;  // Mark node as visited
        for (int i = 0; i < V; i++) {
            // If there is a connection and the node is unvisited
            if (adj[node][i] == 1 && !vis[i]) {
                dfs(i, adj, vis, V);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        int vis[V] = {0};  // Visited array initialized to 0
        int comp = 0;      // Component (province) counter

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                comp++;              // New province found
                dfs(i, adj, vis, V); // Explore all cities in this province
            }
        }
        return comp;
    }
};
