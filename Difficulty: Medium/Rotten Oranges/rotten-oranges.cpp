//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution 
{
    private:
    int bfsHelper(int n, int m, vector<vector<int>>& grid, queue<pair<pair<int,int>, int>>& q, int freshCnt) {
        int row[] = {-1, 0, +1, 0};
        int col[] = {0, +1, 0, -1};
        int maxTime = 0;
        int newlyRotten = 0;

        while (!q.empty()) {
            auto frontNode = q.front();
            q.pop();
            int r = frontNode.first.first;
            int c = frontNode.first.second;
            int t = frontNode.second;
            maxTime = max(maxTime, t);

            for (int i = 0; i < 4; i++) {
                int newRow = r + row[i];
                int newCol = c + col[i];

                // Ensure new coordinates are within bounds and the orange is fresh
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1) {
                    grid[newRow][newCol] = 2; // Mark the orange as rotten
                    q.push({{newRow, newCol}, t + 1});
                    newlyRotten++;
                }
            }
        }

        // If all fresh oranges have been rotted, return maxTime; otherwise, return -1
        return (freshCnt == newlyRotten) ? maxTime : -1;
    }

    public:
    // Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, int>> q;
        int freshCnt = 0;    

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0}); // Push the initially rotten oranges
                } else if (grid[i][j] == 1) {
                    freshCnt++; // Count fresh oranges
                }
            }
        }

        // Call the BFS helper to compute the time
        return bfsHelper(n, m, grid, q, freshCnt);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends