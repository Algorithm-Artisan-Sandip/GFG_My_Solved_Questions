class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        queue<int> q;
        vector<int> bfs;
        int vis[adj.size()] = {0};
        vis[0] = 1;
        q.push(0);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto nbr : adj[node]) {
                if(!vis[nbr]) {
                    vis[nbr] = 1;
                    q.push(nbr);
                }
            }
        }
        return bfs;
    }
};