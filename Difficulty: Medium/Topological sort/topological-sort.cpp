
class Solution {
  private:
    void dfs(int node, int V, stack<int>& st, vector<int>& vis,
             vector<vector<int>>& adjList) {
        vis[node] = 1;  // Mark current node as visited
        // Traverse all unvisited neighbors
        for(auto nbr : adjList[node]) {
            if(!vis[nbr])
                dfs(nbr, V, st, vis, adjList);
        }
        // After visiting all neighbors, push the node to stack
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list from the edge list
        vector<vector<int>> adjList(V);
        for(int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
        }
        stack<int> st;         // Stack to store the topological order
        vector<int> vis(V, 0); // Visited array
        // Step 2: Call DFS for all unvisited nodes
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, V, st, vis, adjList);
            }
        }
        // Step 3: Pop elements from stack to get topological order
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
