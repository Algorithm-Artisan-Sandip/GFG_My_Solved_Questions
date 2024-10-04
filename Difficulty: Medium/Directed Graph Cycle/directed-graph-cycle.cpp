//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool detectCycle(int src, vector<bool>& visited, vector<bool>& dfsTrack, vector<int> adj[]) {
        visited[src] = true;
        dfsTrack[src] = true;
        
        for(auto nbr : adj[src]) {
            if(!visited[nbr]) {
                bool ans = detectCycle(nbr, visited, dfsTrack, adj);
                if(ans) return true;
            }
            else if(dfsTrack[nbr]) return true;
        }
        
        // backtrack : 
        dfsTrack[src] = false;
        
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        if(V == 0) return false;
        
        vector<bool> visited(V, false);
        vector<bool> dfsTrack(V, false);
        
        for(int node = 0; node < V; node++) {
            if(!visited[node]) {
                if(detectCycle(node, visited, dfsTrack, adj)) return true;
            }
        }
        
        return false;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends