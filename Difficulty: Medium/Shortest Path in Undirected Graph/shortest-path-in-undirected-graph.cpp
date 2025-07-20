class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& adj,
                             int src) {
        int V = adj.size();
        vector<int> dist(V, INT_MAX);
        dist[src] = 0; // mark the src node dist = 0
        queue<int> q;
        q.push(src);  
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto nbr : adj[node]) {
                // if it is unvisited
                if(dist[nbr] == INT_MAX) {
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                }
            }
        }
        // mark dist -1 for the unreachable nodes
        for(int i=0; i<V; i++) {
            if(dist[i] == INT_MAX)
                dist[i] = -1;
        }
        return dist;
    }
};