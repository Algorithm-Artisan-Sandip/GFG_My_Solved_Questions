//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  private:
    void bfs(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        queue<pair<int, int>> q;
        visited[i][j] = true;
        q.push({i, j});
        
        int row[] = {-1, 0, +1, 0, -1, -1, +1, +1};
        int col[] = {0, +1, 0, -1, -1, +1, +1, -1};
        
        while(!q.empty()) {
            auto frontNode = q.front();
            q.pop();
            int r = frontNode.first;
            int c = frontNode.second;
            
            for(int k = 0; k<8; k++) {
                int newRow = r + row[k];
                int newCol = c + col[k];
                
                if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && !visited[newRow][newCol] && grid[newRow][newCol] == '1') {
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
    }
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false)); 
        
        int islandCnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    islandCnt++;
                    bfs(i, j, n, m, grid, visited);
                }
            }
        }
        
        return islandCnt;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends