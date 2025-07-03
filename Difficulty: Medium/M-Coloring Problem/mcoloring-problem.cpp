class Solution {
  private: 
    bool isSafe(int node , vector<vector<int>>& graph, 
        vector<int>& color, int m, int v) {
        for(int i = 0 ; i < v ; i++) {
            // if conneted nodes have same color then it's not safe
            if(graph[node][i] == 1 && color[i] == m) return false;
        }
        return true;
    }
    bool findAns(int node , vector<vector<int>>& graph, 
        vector<int>& color, int m, int v) {
        if(node == v) return true;
        
        for(int i = 1 ; i <= m ; i++) {
            if(isSafe(node, graph, color, i, v)) {
                color[node] = i; // assign color
                // recurse for next node
                if(findAns(node + 1, graph, color, m, v)) return true; 
                color[node] = 0; // backtrack
            }
        }
        return false; // no valid coloring found
    }
  public:
    bool graphColoring(int v, vector<vector<int>> &edge, int m) {
        // adjacency matrix of size v x v initialized to 0
        vector<vector<int>> graph(v, vector<int>(v, 0));
        // Convert edge list to adjacency matrix
        for(int i = 0 ; i < edge.size(); i++) {
            graph[edge[i][0]][edge[i][1]] = 1;
            graph[edge[i][1]][edge[i][0]] = 1; // undirected graph
        }
        vector<int> color(v , 0); // initially all vertex has color 0
        // Start coloring from the first node
        return findAns(0, graph, color, m, v);
    }
};
