class Solution {
private:
    void dfs(int src, int dest, int& cnt,
             vector<int> adj[]) {
        if (src == dest) {
            cnt++;
            return;
        }
        for (int nbr : adj[src]) {
            dfs(nbr, dest, cnt, adj);
        }
    }

public:
    int countPaths(int V, vector<int> adj[],
                   int source, int destination) {
        int cnt = 0;
        dfs(source, destination, cnt, adj);
        return cnt;
    }
};
