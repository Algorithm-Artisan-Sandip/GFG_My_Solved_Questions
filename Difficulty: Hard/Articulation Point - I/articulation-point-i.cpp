// User function Template for C++

class Solution {
  private:
    int timer = 1;
    // Helper DFS function to find articulation points using Tarjan's Algorithm
    void dfs(int node, int parent, vector<int>& vis, vector<int>& insertTime, 
             vector<int>& lowestTime, vector<int> adj[], vector<int>& mark) {
        // Mark the node as visited and initialize discovery and low times
        vis[node] = 1;
        insertTime[node] = lowestTime[node] = timer++;
        int child = 0;  // Count of child nodes in DFS tree
        for(auto nbr : adj[node]) {
            if(nbr == parent) continue; // Skip the parent node
            if(!vis[nbr]) {
                // Recur for unvisited neighbor
                dfs(nbr, node, vis, insertTime, lowestTime, adj, mark);
                // After returning, update the low time of current node
                lowestTime[node] = min(lowestTime[node], lowestTime[nbr]);
                // Articulation point check (not root)
                if(lowestTime[nbr] >= insertTime[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            }
            else {
                // If already visited, update low time using back edge
                lowestTime[node] = min(lowestTime[node], insertTime[nbr]);
            }
        }
        // Articulation point check for root node
        if(parent == -1 && child > 1) {
            mark[node] = 1;
        }
    }
  public:
    vector<int> articulationPoints(int n, vector<int> adj[]) {
        vector<int> vis(n, 0);         // Visited array
        vector<int> insertTime(n, 0);  // Discovery time
        vector<int> lowestTime(n, 0);  // Lowest reachable time
        vector<int> mark(n, 0);        // Marks articulation points
        // Apply DFS on each unvisited component
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, -1, vis, insertTime, lowestTime, adj, mark);
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(mark[i] == 1) {
                ans.push_back(i);
            }
        }
        // If no articulation point found, return {-1} as per convention
        if(ans.empty()) return {-1};
        return ans;
    }
};
