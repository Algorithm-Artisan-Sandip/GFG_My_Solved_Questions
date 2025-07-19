class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Step 1: Create the adjacency list
        // For a prerequisite pair {u, v}, course 'u' depends on course 'v' → edge: v -> u
        vector<vector<int>> adjList(N);
        for(auto it : prerequisites) {
            adjList[it.second].push_back(it.first);   
        }
        // Step 2: Compute the in-degree of each node
        vector<int> indegree(N, 0);
        for(int i = 0; i < N; i++) {
            for(auto nbr : adjList[i]) {
                indegree[nbr]++;
            }
        }
        // Step 3: Push all nodes with in-degree 0 into the queue
        queue<int> q;
        for(int i = 0; i < N; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        // Step 4: Perform Kahn's Algorithm (BFS-based Topological Sort)
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            // Reduce in-degree of adjacent nodes
            for(auto nbr : adjList[node]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        // Step 5: If topological sort includes all N nodes, then no cycle exists
        // Hence, it's possible to finish all courses
        return (topo.size() == N);
    }
};
