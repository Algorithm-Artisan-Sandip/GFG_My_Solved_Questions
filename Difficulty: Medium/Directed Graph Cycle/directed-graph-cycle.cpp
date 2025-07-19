
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // Step 1: Create adjacency list from the given edge list
        vector<vector<int>> adjList(V);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);  // directed edge u -> v
        }
        // Step 2: Initialize indegree of each vertex
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++) {
            for(auto nbr : adjList[i]) {
                indegree[nbr]++;  // Count incoming edges
            }
        }
        // Step 3: Push all vertices with 0 indegree into the queue
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        // Step 4: Perform BFS (Kahn's Algorithm) for topological sort
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);  // Add node to topological order

            // Decrease indegree of adjacent nodes
            for(auto nbr : adjList[node]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);  // If indegree becomes 0, add to queue
                }
            }
        }
        // Step 5: If topo sort contains all vertices, no cycle exists
        // Otherwise, a cycle is present in the graph
        return (topo.size() == V) ? false : true;
    }
};
