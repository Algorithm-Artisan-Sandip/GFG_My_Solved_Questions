class Solution {
  private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis,
             vector<vector<int>>& adjList) {
        vis[node] = 1;        // Mark current node as visited
        pathVis[node] = 1;    // Mark current node in the recursion stack (path)
        for(auto& nbr : adjList[node]) {
            // If neighbor is not visited, do DFS on it
            if(!vis[nbr]) {
                if(dfs(nbr, vis, pathVis, adjList)) {
                    return true; // Cycle detected in DFS subtree
                } 
            }
            // If neighbor is visited and also in the current path → cycle found
            else if(pathVis[nbr] == 1) {
                return true;
            }
        }
        // Backtrack: remove node from current path
        pathVis[node] = 0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // Create adjacency list from edges
        vector<vector<int>> adjList(V);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v); // Directed edge from u to v
        }
        // Arrays to keep track of visited nodes and recursion path
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        // Run DFS for each unvisited node
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(i, vis, pathVis, adjList)) {
                    return true; // Cycle detected
                }
            }
        }
        return false; // No cycle found in any component
    }
};
