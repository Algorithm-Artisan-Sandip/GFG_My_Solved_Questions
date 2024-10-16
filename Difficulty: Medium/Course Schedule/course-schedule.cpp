//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  private:
    void topoSort(int n, vector<int>& topoOrder, unordered_map<int, list<int>>& adjList) {
        queue<int> q;
        vector<int> indegree(n, 0);
        
        // storing the indegrees : 
        for(auto it : adjList) {
            for(auto nbr : it.second) {
                indegree[nbr]++;
            }
        }
        
        // storing the nodes with zero indegree in the queue : 
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        // actual bfs logic : 
        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();
            topoOrder.push_back(frontNode);
            
            for(auto nbr : adjList[frontNode]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }
    
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        unordered_map<int, list<int>> adjList;
        for(vector<int> it : prerequisites) {
            int u = it[0];
            int v = it[1];
            adjList[v].push_back(u);
        }
        
        vector<int> topoOrder;
        topoSort(n, topoOrder, adjList);
        
        if(topoOrder.size() == n) return topoOrder;
        else return {};
    }
};


//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends