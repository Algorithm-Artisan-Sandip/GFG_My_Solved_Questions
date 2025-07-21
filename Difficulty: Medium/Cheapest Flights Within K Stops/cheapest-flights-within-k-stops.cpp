class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int m = flights.size();
        // Step 1: Create adjacency list for the graph
        // Each entry adjList[u] contains pairs (v, cost), representing a flight from u to v with given cost.
        vector<vector<pair<int, int>>> adjList(n);
        for(int i = 0; i < m; i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int cost = flights[i][2];
            adjList[u].push_back({v, cost});
        }
        // Step 2: BFS with tracking of stops
        // Each queue element stores: (stops, (current node, total cost to reach this node))
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});  // Start from src node with 0 stops and 0 cost
        // Step 3: Distance array to track minimum cost to reach each node
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while(!q.empty()) {
            auto front = q.front();
            int stops = front.first;
            int currNode = front.second.first;
            int cost = front.second.second;
            q.pop();
            // If stops exceed allowed K, skip this path
            if(stops > K) continue;
            // Traverse neighbors
            for(auto nbr : adjList[currNode]) {
                int adjNode = nbr.first;
                int currCost = nbr.second;
                // If we find a cheaper path to adjNode within K stops, update and push to queue
                if(cost + currCost < dist[adjNode]) {
                    dist[adjNode] = cost + currCost;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }
        // If destination node is unreachable, return -1
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};
