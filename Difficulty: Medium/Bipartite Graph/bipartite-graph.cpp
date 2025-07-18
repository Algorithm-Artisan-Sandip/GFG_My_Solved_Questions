class Solution {
  private:
    bool dfs(int node, vector<int>& color, vector<vector<int>>& adjList) {
        for(auto nbr : adjList[node]) {
            // If neighbor has not been colored, assign opposite color
            if(color[nbr] == -1) {
                color[nbr] = !color[node]; // Alternate the color
                if(dfs(nbr, color, adjList) == false)
                    return false;
            }
            // If neighbor has same color as current node, it's not bipartite
            else if(color[nbr] == color[node]) {
                return false;
            }
        }
        return true; // This component is bipartite
    }
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Initialize color array with -1 (unvisited)
        vector<int> color(V, -1);
        // Build the adjacency list from edge list
        vector<vector<int>> adjList(V);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u); // Since the graph is undirected
        }
        // Traverse all vertices (for disconnected components)
        for(int i = 0; i < V; i++) {
            if(color[i] == -1) {
                color[i] = 0; // Start coloring the node with color 0
                // If any component is not bipartite, return false
                if(!dfs(i, color, adjList))
                    return false;
            }
        }
        return true; // All components are bipartite
    }
};
