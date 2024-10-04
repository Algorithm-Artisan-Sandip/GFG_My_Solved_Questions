//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detectCycle(int src, vector<bool>& visited, vector<int> adj[]) {
        queue<int> q;
        vector<int> parent(visited.size(), -1);
        
        // maintaining initial state : 
        q.push(src);
        visited[src] = true;
        
        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();
            
            for(auto nbr : adj[frontNode]) {
                if(!visited[nbr]) {
                    parent[nbr] = frontNode;
                    visited[nbr] = true;
                    q.push(nbr);
                }
                else {
                    if(parent[frontNode] != nbr) return true;
                }
            }
        }
        return false;
             
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        if(V == 0) return false;
        
        vector<bool> visited(V, false);
        
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                if(detectCycle(i, visited, adj))
                    return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends