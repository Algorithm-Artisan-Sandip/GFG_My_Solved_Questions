// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // Step 1: Reverse the edges of the graph
        // This helps us find nodes that eventually lead to terminal nodes
        vector<vector<int>> adjRev(V);
        for(int i = 0; i < V; i++) {
            for(auto nbr : adj[i]) {
                adjRev[nbr].push_back(i); // Reverse the edge
            }
        }
        // Step 2: Create indegree array for reversed graph
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++) {
            for(auto nbr : adjRev[i]) {
                indegree[nbr]++;
            }
        }
        // Step 3: Add all nodes with 0 indegree in reversed graph to the queue
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i); // These are terminal nodes in original graph
            }
        }
        // Step 4: Perform BFS (Kahn's Algorithm) on the reversed graph
        vector<int> safeNodes;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node); // Node is safe
            // Reduce the indegree of neighbours
            for(auto nbr : adjRev[node]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        // Step 5: Sort the result to return nodes in increasing order
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
