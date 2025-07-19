
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list from the edge list
        vector<vector<int>> adjList(V);
        for(int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> topo; // Stores the final topological order
        // Tracks the number of incoming edges for each node
        vector<int> indegree(V, 0);
        queue<int> q; // Queue for nodes with 0 indegree
        // Step 2: Create the indegree vector
        for(int i = 0; i < V; i++) {
            for(auto nbr : adjList[i]) {
                indegree[nbr]++; // Count incoming edges for each neighbor
            }
        }
        // Step 3: Add all nodes with 0 indegree to the queue
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        // Step 4: Process nodes using BFS
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);     // Add node to topological order
            // Decrease indegree of neighbors
            for(auto nbr : adjList[node]) {
                indegree[nbr]--;
                // If indegree becomes 0, add to queue
                if(indegree[nbr] == 0) 
                    q.push(nbr);
            }
        }
        // Step 5: Return the result
        return topo;
    }
};


